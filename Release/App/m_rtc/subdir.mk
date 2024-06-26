################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/m_rtc/m_rtc_2001.c 

C_DEPS += \
./App/m_rtc/m_rtc_2001.d 

OBJS += \
./App/m_rtc/m_rtc_2001.o 


# Each subdirectory must supply rules for building sources it contributes
App/m_rtc/%.o App/m_rtc/%.su App/m_rtc/%.cyclo: ../App/m_rtc/%.c App/m_rtc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I.././ -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-m_rtc

clean-App-2f-m_rtc:
	-$(RM) ./App/m_rtc/m_rtc_2001.cyclo ./App/m_rtc/m_rtc_2001.d ./App/m_rtc/m_rtc_2001.o ./App/m_rtc/m_rtc_2001.su

.PHONY: clean-App-2f-m_rtc

