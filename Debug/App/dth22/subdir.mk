################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../App/dth22/dth22.class.cpp 

OBJS += \
./App/dth22/dth22.class.o 

CPP_DEPS += \
./App/dth22/dth22.class.d 


# Each subdirectory must supply rules for building sources it contributes
App/dth22/%.o App/dth22/%.su App/dth22/%.cyclo: ../App/dth22/%.cpp App/dth22/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I.././ -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fexceptions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-dth22

clean-App-2f-dth22:
	-$(RM) ./App/dth22/dth22.class.cyclo ./App/dth22/dth22.class.d ./App/dth22/dth22.class.o ./App/dth22/dth22.class.su

.PHONY: clean-App-2f-dth22

