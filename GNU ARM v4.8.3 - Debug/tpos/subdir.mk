################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tpos/low_power_tick_management.c \
../tpos/sleep.c \
../tpos/tpos_croutine.c \
../tpos/tpos_heap_1.c \
../tpos/tpos_list.c \
../tpos/tpos_port.c \
../tpos/tpos_queue.c \
../tpos/tpos_tasks.c \
../tpos/tpos_timers.c 

OBJS += \
./tpos/low_power_tick_management.o \
./tpos/sleep.o \
./tpos/tpos_croutine.o \
./tpos/tpos_heap_1.o \
./tpos/tpos_list.o \
./tpos/tpos_port.o \
./tpos/tpos_queue.o \
./tpos/tpos_tasks.o \
./tpos/tpos_timers.o 

C_DEPS += \
./tpos/low_power_tick_management.d \
./tpos/sleep.d \
./tpos/tpos_croutine.d \
./tpos/tpos_heap_1.d \
./tpos/tpos_list.d \
./tpos/tpos_port.d \
./tpos/tpos_queue.d \
./tpos/tpos_tasks.d \
./tpos/tpos_timers.d 


# Each subdirectory must supply rules for building sources it contributes
tpos/low_power_tick_management.o: ../tpos/low_power_tick_management.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/low_power_tick_management.d" -MT"tpos/low_power_tick_management.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/sleep.o: ../tpos/sleep.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/sleep.d" -MT"tpos/sleep.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_croutine.o: ../tpos/tpos_croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_croutine.d" -MT"tpos/tpos_croutine.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_heap_1.o: ../tpos/tpos_heap_1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_heap_1.d" -MT"tpos/tpos_heap_1.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_list.o: ../tpos/tpos_list.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_list.d" -MT"tpos/tpos_list.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_port.o: ../tpos/tpos_port.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_port.d" -MT"tpos/tpos_port.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_queue.o: ../tpos/tpos_queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_queue.d" -MT"tpos/tpos_queue.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_tasks.o: ../tpos/tpos_tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_tasks.d" -MT"tpos/tpos_tasks.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tpos/tpos_timers.o: ../tpos/tpos_timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"tpos/tpos_timers.d" -MT"tpos/tpos_timers.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


