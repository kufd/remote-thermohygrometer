################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../App/ssd1306/fonts.cpp \
../App/ssd1306/ssd1306.cpp 

OBJS += \
./App/ssd1306/fonts.o \
./App/ssd1306/ssd1306.o 

CPP_DEPS += \
./App/ssd1306/fonts.d \
./App/ssd1306/ssd1306.d 


# Each subdirectory must supply rules for building sources it contributes
App/ssd1306/%.o App/ssd1306/%.su App/ssd1306/%.cyclo: ../App/ssd1306/%.cpp App/ssd1306/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I.././ -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-ssd1306

clean-App-2f-ssd1306:
	-$(RM) ./App/ssd1306/fonts.cyclo ./App/ssd1306/fonts.d ./App/ssd1306/fonts.o ./App/ssd1306/fonts.su ./App/ssd1306/ssd1306.cyclo ./App/ssd1306/ssd1306.d ./App/ssd1306/ssd1306.o ./App/ssd1306/ssd1306.su

.PHONY: clean-App-2f-ssd1306

