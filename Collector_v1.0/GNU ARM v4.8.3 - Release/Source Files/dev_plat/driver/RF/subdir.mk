################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source\ Files/dev_plat/driver/RF/radio_hal.c \
../Source\ Files/dev_plat/driver/RF/rf_spi.c \
../Source\ Files/dev_plat/driver/RF/si446x_api_lib.c \
../Source\ Files/dev_plat/driver/RF/si446x_nirq.c 

OBJS += \
./Source\ Files/dev_plat/driver/RF/radio_hal.o \
./Source\ Files/dev_plat/driver/RF/rf_spi.o \
./Source\ Files/dev_plat/driver/RF/si446x_api_lib.o \
./Source\ Files/dev_plat/driver/RF/si446x_nirq.o 

C_DEPS += \
./Source\ Files/dev_plat/driver/RF/radio_hal.d \
./Source\ Files/dev_plat/driver/RF/rf_spi.d \
./Source\ Files/dev_plat/driver/RF/si446x_api_lib.d \
./Source\ Files/dev_plat/driver/RF/si446x_nirq.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/dev_plat/driver/RF/radio_hal.o: ../Source\ Files/dev_plat/driver/RF/radio_hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/dev_plat/driver/RF/radio_hal.d" -MT"Source\ Files/dev_plat/driver/RF/radio_hal.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/dev_plat/driver/RF/rf_spi.o: ../Source\ Files/dev_plat/driver/RF/rf_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/dev_plat/driver/RF/rf_spi.d" -MT"Source\ Files/dev_plat/driver/RF/rf_spi.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/dev_plat/driver/RF/si446x_api_lib.o: ../Source\ Files/dev_plat/driver/RF/si446x_api_lib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/dev_plat/driver/RF/si446x_api_lib.d" -MT"Source\ Files/dev_plat/driver/RF/si446x_api_lib.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/dev_plat/driver/RF/si446x_nirq.o: ../Source\ Files/dev_plat/driver/RF/si446x_nirq.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/dev_plat/driver/RF/si446x_nirq.d" -MT"Source\ Files/dev_plat/driver/RF/si446x_nirq.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


