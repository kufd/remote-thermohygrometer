#ifndef __APP_H
#define __APP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"


void appMain(I2C_HandleTypeDef *carrierLcdI2C, SPI_HandleTypeDef *carrierLoRaSPI);


#ifdef __cplusplus
}
#endif

#endif /* __APP_H */
