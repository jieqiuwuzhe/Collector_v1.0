################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/rs_232/rs_232.c 

OBJS += \
./driver/rs_232/rs_232.o 

C_DEPS += \
./driver/rs_232/rs_232.d 


# Each subdirectory must supply rules for building sources it contributes
driver/rs_232/rs_232.o: ../driver/rs_232/rs_232.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32G280F128=1' -I"E:/test_Collector_V1.0/Collector_v1.0/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32G/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\flash" -I"E:\test_Collector_V1.0\Collector_v1.0\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\driver\RF\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\inc" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos\driver" -I"E:\test_Collector_V1.0\Collector_v1.0\tpos" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"driver/rs_232/rs_232.d" -MT"driver/rs_232/rs_232.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


