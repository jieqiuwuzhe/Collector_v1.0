################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../emlib/dmactrl.c \
../emlib/em_adc.c \
../emlib/em_cmu.c \
../emlib/em_dma.c \
../emlib/em_emu.c \
../emlib/em_gpio.c \
../emlib/em_i2c.c \
../emlib/em_int.c \
../emlib/em_letimer.c \
../emlib/em_leuart.c \
../emlib/em_rtc.c \
../emlib/em_system.c \
../emlib/em_timer.c \
../emlib/em_usart.c \
../emlib/em_wdog.c 

OBJS += \
./emlib/dmactrl.o \
./emlib/em_adc.o \
./emlib/em_cmu.o \
./emlib/em_dma.o \
./emlib/em_emu.o \
./emlib/em_gpio.o \
./emlib/em_i2c.o \
./emlib/em_int.o \
./emlib/em_letimer.o \
./emlib/em_leuart.o \
./emlib/em_rtc.o \
./emlib/em_system.o \
./emlib/em_timer.o \
./emlib/em_usart.o \
./emlib/em_wdog.o 

C_DEPS += \
./emlib/dmactrl.d \
./emlib/em_adc.d \
./emlib/em_cmu.d \
./emlib/em_dma.d \
./emlib/em_emu.d \
./emlib/em_gpio.d \
./emlib/em_i2c.d \
./emlib/em_int.d \
./emlib/em_letimer.d \
./emlib/em_leuart.d \
./emlib/em_rtc.d \
./emlib/em_system.d \
./emlib/em_timer.d \
./emlib/em_usart.d \
./emlib/em_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/dmactrl.o: ../emlib/dmactrl.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/dmactrl.d" -MT"emlib/dmactrl.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_adc.o: ../emlib/em_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_adc.d" -MT"emlib/em_adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cmu.o: ../emlib/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_cmu.d" -MT"emlib/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_dma.o: ../emlib/em_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_dma.d" -MT"emlib/em_dma.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: ../emlib/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_emu.d" -MT"emlib/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_gpio.o: ../emlib/em_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_gpio.d" -MT"emlib/em_gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_i2c.o: ../emlib/em_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_i2c.d" -MT"emlib/em_i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_int.o: ../emlib/em_int.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_int.d" -MT"emlib/em_int.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_letimer.o: ../emlib/em_letimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_letimer.d" -MT"emlib/em_letimer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_leuart.o: ../emlib/em_leuart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_leuart.d" -MT"emlib/em_leuart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rtc.o: ../emlib/em_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_rtc.d" -MT"emlib/em_rtc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: ../emlib/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_system.d" -MT"emlib/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_timer.o: ../emlib/em_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_timer.d" -MT"emlib/em_timer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_usart.o: ../emlib/em_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_usart.d" -MT"emlib/em_usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_wdog.o: ../emlib/em_wdog.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\app_plat" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\fun" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPRS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPS" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RF" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\RS232" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\R8025T" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat\driver\GPIO" -I"E:\test_Collector_V1.0\Collector_v1.0\Header Files\dev_plat" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_wdog.d" -MT"emlib/em_wdog.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


