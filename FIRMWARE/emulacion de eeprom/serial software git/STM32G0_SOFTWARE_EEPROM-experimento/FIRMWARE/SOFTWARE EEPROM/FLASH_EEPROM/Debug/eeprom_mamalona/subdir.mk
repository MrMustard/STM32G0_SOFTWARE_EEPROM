################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../eeprom_mamalona/eeprom_mamalona.c 

OBJS += \
./eeprom_mamalona/eeprom_mamalona.o 

C_DEPS += \
./eeprom_mamalona/eeprom_mamalona.d 


# Each subdirectory must supply rules for building sources it contributes
eeprom_mamalona/%.o eeprom_mamalona/%.su: ../eeprom_mamalona/%.c eeprom_mamalona/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/pc/Desktop/serial software git/STM32G0_SOFTWARE_EEPROM-experimento/FIRMWARE/SOFTWARE EEPROM/FLASH_EEPROM/serial_uart" -I"C:/Users/pc/Desktop/serial software git/STM32G0_SOFTWARE_EEPROM-experimento/FIRMWARE/SOFTWARE EEPROM/FLASH_EEPROM/eeprom_mamalona" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-eeprom_mamalona

clean-eeprom_mamalona:
	-$(RM) ./eeprom_mamalona/eeprom_mamalona.d ./eeprom_mamalona/eeprom_mamalona.o ./eeprom_mamalona/eeprom_mamalona.su

.PHONY: clean-eeprom_mamalona

