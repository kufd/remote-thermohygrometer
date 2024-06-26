/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void microDelay(uint32_t microSeconds);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SYSTEM_WAKEUP_Pin GPIO_PIN_0
#define SYSTEM_WAKEUP_GPIO_Port GPIOA
#define DTH_22_Pin GPIO_PIN_4
#define DTH_22_GPIO_Port GPIOA
#define LORA_SCK_Pin GPIO_PIN_5
#define LORA_SCK_GPIO_Port GPIOA
#define LORA_MISO_Pin GPIO_PIN_6
#define LORA_MISO_GPIO_Port GPIOA
#define LORA_MOSI_Pin GPIO_PIN_7
#define LORA_MOSI_GPIO_Port GPIOA
#define SENSORS_POWER_Pin GPIO_PIN_12
#define SENSORS_POWER_GPIO_Port GPIOB
#define DISPLAY_POWER_Pin GPIO_PIN_13
#define DISPLAY_POWER_GPIO_Port GPIOB
#define NSS_Pin GPIO_PIN_3
#define NSS_GPIO_Port GPIOB
#define DIO0_Pin GPIO_PIN_5
#define DIO0_GPIO_Port GPIOB
#define RESET_Pin GPIO_PIN_6
#define RESET_GPIO_Port GPIOB
#define MODE_Pin GPIO_PIN_7
#define MODE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
