################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tpos/subdir.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include driver/rs_232/subdir.mk
-include driver/flash/subdir.mk
-include driver/RF/fun/subdir.mk
-include CMSIS/efm32g/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Collector_v1.0.axf

# Tool invocations
Collector_v1.0.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "Collector_v1.0.ld" -Xlinker --gc-sections -Xlinker -Map="Collector_v1.0.map" --specs=nano.specs -o Collector_v1.0.axf "./tpos/low_power_tick_management.o" "./tpos/sleep.o" "./tpos/tpos_croutine.o" "./tpos/tpos_heap_1.o" "./tpos/tpos_list.o" "./tpos/tpos_port.o" "./tpos/tpos_queue.o" "./tpos/tpos_tasks.o" "./tpos/tpos_timers.o" "./src/InitDevice.o" "./src/app_task.o" "./src/main.o" "./emlib/dmactrl.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_dma.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_int.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_wdog.o" "./driver/rs_232/rs_232.o" "./driver/flash/flash_fun.o" "./driver/RF/fun/radio_hal.o" "./driver/RF/fun/rf_spi.o" "./driver/RF/fun/si446x_api_lib.o" "./driver/RF/fun/si446x_nirq.o" "./CMSIS/efm32g/startup_gcc_efm32g.o" "./CMSIS/efm32g/system_efm32g.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: Collector_v1.0.hex'
	arm-none-eabi-objcopy -O ihex "Collector_v1.0.axf" "Collector_v1.0.hex"
	@echo ' '

	@echo 'Building bin file: Collector_v1.0.bin'
	arm-none-eabi-objcopy -O binary "Collector_v1.0.axf" "Collector_v1.0.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Collector_v1.0.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Collector_v1.0.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
