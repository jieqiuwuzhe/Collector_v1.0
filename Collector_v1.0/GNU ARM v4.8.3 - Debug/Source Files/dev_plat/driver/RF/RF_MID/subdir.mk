################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source\ Files/dev_plat/driver/RF/RF_MID/MID.c 

OBJS += \
./Source\ Files/dev_plat/driver/RF/RF_MID/MID.o 

C_DEPS += \
./Source\ Files/dev_plat/driver/RF/RF_MID/MID.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/dev_plat/driver/RF/RF_MID/MID.o: ../Source\ Files/dev_plat/driver/RF/RF_MID/MID.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF\RF_APP" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF\RF_DB" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF\RF_MAC" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF\RF_MID" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF\RF_PROTOCOL" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/dev_plat/driver/RF/RF_MID/MID.d" -MT"Source\ Files/dev_plat/driver/RF/RF_MID/MID.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


