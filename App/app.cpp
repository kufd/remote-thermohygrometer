#include "app.h"
#include "App/ssd1306/ssd1306.h"
#include "App/SX1278/SX1278.h"
#include "App/dth22/dth22.class.h"
#include <stdio.h>

I2C_HandleTypeDef *lcdI2C;
SPI_HandleTypeDef *loRaSPI;
SX1278_hw_t SX1278_hw;
SX1278_t SX1278;

void displayState(float tempC, float humidity);
void sendState(const char* id, float tempC, float humidity, const char* dateTime);
void initSX1278();

void appMain(I2C_HandleTypeDef *carrierLcdI2C, SPI_HandleTypeDef *carrierLoRaSPI)
{
    HAL_GPIO_WritePin(SENSORS_POWER_GPIO_Port, SENSORS_POWER_Pin, GPIO_PIN_SET);

    GPIO_PinState systemWakeupButtonPressed = HAL_GPIO_ReadPin(SYSTEM_WAKEUP_GPIO_Port, SYSTEM_WAKEUP_Pin);

    lcdI2C = carrierLcdI2C;
    loRaSPI = carrierLoRaSPI;

    if (systemWakeupButtonPressed)
    {
        HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, GPIO_PIN_SET);
        ssd1306_Init(lcdI2C);
    }

    initSX1278();

    DTH22 dth22(DTH_22_GPIO_Port, DTH_22_Pin);

	while (1)
	{
	    EnvironmentConditions environmentConditions = dth22.read();
	    if (!environmentConditions.isValid)
	    {
	        continue;
	    }

	    EnvironmentConditions environmentConditionsVarification = dth22.read();
        if (!environmentConditionsVarification.isValid)
        {
            continue;
        }

        //if environmentConditions measured nearly at the same time are not similar then try to measure them again
        if (!environmentConditions.isSimilar(environmentConditionsVarification))
        {
            continue;
        }

	    if (systemWakeupButtonPressed)
	    {
	        displayState(environmentConditions.tempC, environmentConditions.humidity);
	    }

        sendState("loft", environmentConditions.tempC, environmentConditions.humidity, "10:00 12.03");

        //keep on when SYSTEM WAKEUP button is pressed
        while(HAL_GPIO_ReadPin(SYSTEM_WAKEUP_GPIO_Port, SYSTEM_WAKEUP_Pin) == GPIO_PIN_SET);

        break;
	}

	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SENSORS_POWER_GPIO_Port, SENSORS_POWER_Pin, GPIO_PIN_RESET);
}

void initSX1278()
{
    SX1278_hw.dio0.port = DIO0_GPIO_Port;
    SX1278_hw.dio0.pin = DIO0_Pin;
    SX1278_hw.nss.port = NSS_GPIO_Port;
    SX1278_hw.nss.pin = NSS_Pin;
    SX1278_hw.reset.port = RESET_GPIO_Port;
    SX1278_hw.reset.pin = RESET_Pin;
    SX1278_hw.spi = loRaSPI;

    SX1278.hw = &SX1278_hw;

    SX1278_init(&SX1278, 434000000, SX1278_POWER_17DBM, SX1278_LORA_SF_7, SX1278_LORA_BW_125KHZ, SX1278_LORA_CR_4_5, SX1278_LORA_CRC_EN, 10);

    SX1278_LoRaEntryTx(&SX1278, 16, 2000);
}

void sendState(const char* id, float tempC, float humidity, const char* dateTime)
{
    char payload[100];
    uint8_t payloadLength = sprintf(payload, "%s,%.1f,%.1f,%s", id, tempC, humidity, "10:00 12.03");

    uint16_t checkSum = 0;
    for (uint8_t i=0; i<payloadLength; i++) {
        checkSum += payload[i];
    }

    char message[128];
    int messageLength = sprintf(message, "%s,%d", payload, checkSum);

    SX1278_standby(&SX1278);

    SX1278_LoRaEntryTx(&SX1278, messageLength, 2000);
    SX1278_LoRaTxPacket(&SX1278, (uint8_t*) message, messageLength, 2000);

    SX1278_sleep(&SX1278);
}

void displayState(float tempC, float humidity)
{
    char tempDisplay[20];
    sprintf(tempDisplay, "%.1fC", tempC);

    char humidityDisplay[20];
    sprintf(humidityDisplay, "%.1f%%", humidity);

    ssd1306_Fill(Black);

    ssd1306_SetCursor(20, 0);
    ssd1306_WriteString(tempDisplay, Font_16x26, White);

    ssd1306_SetCursor(20, 35);
    ssd1306_WriteString(humidityDisplay, Font_16x26, White);

    ssd1306_UpdateScreen(lcdI2C);
}
