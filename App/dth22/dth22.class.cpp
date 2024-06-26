#include "dth22.class.h"

DTH22::DTH22(GPIO_TypeDef *gpio, uint16_t gpioPin)
{
	this->gpio = gpio;
	this->gpioPin = gpioPin;
}

EnvironmentConditions DTH22::read()
{
	if(!dht22Start())
	{
	    return EnvironmentConditions {0, 0, false};
	}

	uint8_t hum1 = dht22ReadByte();
	uint8_t hum2 = dht22ReadByte();
	uint8_t tempC1 = dht22ReadByte();
	uint8_t tempC2 = dht22ReadByte();
	uint8_t checkSumReceived = dht22ReadByte();
	uint8_t checkSumCalculated = hum1 + hum2 + tempC1 + tempC2;

	if (checkSumCalculated != checkSumReceived)
	{
	    return EnvironmentConditions {0, 0, false};
	}

	float tempC = (float) ((tempC1<<8)|tempC2)/10;
	float humidity =(float) ((hum1<<8)|hum2)/10;
	bool isValid = tempC >= MIN_TEMP_C && tempC <= MAX_TEMP_C && humidity >= MIN_HUMIDITY_PERCENT && humidity <= MAX_HUMIDITY_PERCENT;

	return EnvironmentConditions {tempC, humidity, isValid};
}

bool DTH22::dht22Start()
{
	uint8_t response = false;

	//make GPIO output
	GPIO_InitTypeDef GPIO_InitStructPrivate = {0};
	GPIO_InitStructPrivate.Pin = gpioPin;
	GPIO_InitStructPrivate.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructPrivate.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructPrivate.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(gpio, &GPIO_InitStructPrivate);

	HAL_GPIO_WritePin (gpio, gpioPin, GPIO_PIN_RESET);
	microDelay (1300);

	HAL_GPIO_WritePin (gpio, gpioPin, GPIO_PIN_SET);
	microDelay (30);

	//make GPIO input
	GPIO_InitStructPrivate.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructPrivate.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(gpio, &GPIO_InitStructPrivate);
	microDelay (40);

	if (!(HAL_GPIO_ReadPin (gpio, gpioPin)))
	{
		microDelay (80);
		if ((HAL_GPIO_ReadPin (gpio, gpioPin)))
		{
			 response = true;
		}
	}

	uint32_t pMillis = HAL_GetTick();
	uint32_t cMillis = HAL_GetTick();

	//wait until pin is low
	while ((HAL_GPIO_ReadPin (gpio, gpioPin)) && pMillis + 2 > cMillis)
	{
		cMillis = HAL_GetTick();
	}

	return response;
}


uint8_t DTH22::dht22ReadByte()
{
	uint8_t byte;

	for (uint8_t bitNumber=0;bitNumber<8;bitNumber++)
	{
		uint32_t pMillis = HAL_GetTick();
		uint32_t cMillis = HAL_GetTick();
		while (!(HAL_GPIO_ReadPin (gpio, gpioPin)) && pMillis + 2 > cMillis)
		{
			cMillis = HAL_GetTick();
		}

		microDelay (40);

		if (HAL_GPIO_ReadPin(gpio, gpioPin))   // if the pin is low
		{
			byte|= (1<<(7-bitNumber));
		}
		else
		{
			byte&= ~(1<<(7-bitNumber));
		}

		pMillis = HAL_GetTick();
		cMillis = HAL_GetTick();
		// wait for the pin to go low
		while ((HAL_GPIO_ReadPin (gpio, gpioPin)) && pMillis + 2 > cMillis)
		{
			cMillis = HAL_GetTick();
		}
	}

	return byte;
}

