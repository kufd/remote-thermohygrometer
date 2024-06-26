################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../App/SX1278/SX1278.cpp \
../App/SX1278/SX1278_hw.cpp 

OBJS += \
./App/SX1278/SX1278.o \
./App/SX1278/SX1278_hw.o 

CPP_DEPS += \
./App/SX1278/SX1278.d \
./App/SX1278/SX1278_hw.d 


# Each subdirectory must supply rules for building sources it contributes
App/SX1278/%.o App/SX1278/%.su App/SX1278/%.cyclo: ../App/SX1278/%.cpp App/SX1278/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I.././ -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-SX1278

clean-App-2f-SX1278:
	-$(RM) ./App/SX1278/SX1278.cyclo ./App/SX1278/SX1278.d ./App/SX1278/SX1278.o ./App/SX1278/SX1278.su ./App/SX1278/SX1278_hw.cyclo ./App/SX1278/SX1278_hw.d ./App/SX1278/SX1278_hw.o ./App/SX1278/SX1278_hw.su

.PHONY: clean-App-2f-SX1278

