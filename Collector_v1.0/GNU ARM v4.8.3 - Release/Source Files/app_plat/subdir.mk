################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source\ Files/app_plat/InitDevice.c \
../Source\ Files/app_plat/app_task.c \
../Source\ Files/app_plat/interrupt.c \
../Source\ Files/app_plat/main.c 

OBJS += \
./Source\ Files/app_plat/InitDevice.o \
./Source\ Files/app_plat/app_task.o \
./Source\ Files/app_plat/interrupt.o \
./Source\ Files/app_plat/main.o 

C_DEPS += \
./Source\ Files/app_plat/InitDevice.d \
./Source\ Files/app_plat/app_task.d \
./Source\ Files/app_plat/interrupt.d \
./Source\ Files/app_plat/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/app_plat/InitDevice.o: ../Source\ Files/app_plat/InitDevice.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/app_plat/InitDevice.d" -MT"Source\ Files/app_plat/InitDevice.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/app_plat/app_task.o: ../Source\ Files/app_plat/app_task.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/app_plat/app_task.d" -MT"Source\ Files/app_plat/app_task.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/app_plat/interrupt.o: ../Source\ Files/app_plat/interrupt.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/app_plat/interrupt.d" -MT"Source\ Files/app_plat/interrupt.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/app_plat/main.o: ../Source\ Files/app_plat/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_restart0818/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\app_plat" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_restart0818\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Source Files/app_plat/main.d" -MT"Source\ Files/app_plat/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


