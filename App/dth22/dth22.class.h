#ifndef __DTH22_CLASS_H
#define __DTH22_CLASS_H

#include <stdexcept>
#include <exception>
#include "main.h"
#include <string.h>
#include <cmath>

//make result and exception general. To be able to reuse in future if we have other sensors
struct EnvironmentConditions
{
	float tempC;
	float humidity;
	bool isValid;

	bool isSame(EnvironmentConditions &that)
	{
		return fabs(this->tempC - that.tempC) <= 0.01 && fabs(this->humidity - that.humidity) <= 0.01 && this->isValid == that.isValid;
	}

	bool isSimilar(EnvironmentConditions &that)
	{
	    return fabs(this->tempC - that.tempC) <= 0.1 && fabs(this->humidity - that.humidity) <= 1.0 && this->isValid == that.isValid;
	}
};

//https://microcontrollerslab.com/dht22-stm32-blue-pill-stm32cubeide/
//https://controllerstech.com/temperature-measurement-using-dht22-in-stm32/
class DTH22
{
	private:
        const int8_t MIN_TEMP_C = -40;
        const int8_t MAX_TEMP_C = 80;
        const int8_t MIN_HUMIDITY_PERCENT = 0;
        const int8_t MAX_HUMIDITY_PERCENT = 100;

		GPIO_TypeDef *gpio;
		uint16_t gpioPin;
	public:
		DTH22(GPIO_TypeDef *gpio, uint16_t gpioPin);
		EnvironmentConditions read();
	private:
		bool dht22Start();
		uint8_t dht22ReadByte();
};

#endif
