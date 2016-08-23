################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include emlib/subdir.mk
-include Source\ Files/dev_plat/tpos/subdir.mk
-include Source\ Files/dev_plat/fun/subdir.mk
-include Source\ Files/dev_plat/driver/flash/subdir.mk
-include Source\ Files/dev_plat/driver/RS232/subdir.mk
-include Source\ Files/dev_plat/driver/RF/subdir.mk
-include Source\ Files/dev_plat/driver/R8025T/subdir.mk
-include Source\ Files/dev_plat/driver/GPS/subdir.mk
-include Source\ Files/dev_plat/driver/GPIO/subdir.mk
-include Source\ Files/dev_plat/subdir.mk
-include Source\ Files/app_plat/subdir.mk
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
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "Collector_v1.0.ld" -Xlinker --gc-sections -Xlinker -Map="Collector_v1.0.map" --specs=nano.specs -o Collector_v1.0.axf "./emlib/dmactrl.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_dma.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_int.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_wdog.o" "./Source Files/dev_plat/var.o" "./Source Files/dev_plat/tpos/low_power_tick_management.o" "./Source Files/dev_plat/tpos/sleep.o" "./Source Files/dev_plat/tpos/tpos_croutine.o" "./Source Files/dev_plat/tpos/tpos_heap_1.o" "./Source Files/dev_plat/tpos/tpos_list.o" "./Source Files/dev_plat/tpos/tpos_port.o" "./Source Files/dev_plat/tpos/tpos_queue.o" "./Source Files/dev_plat/tpos/tpos_tasks.o" "./Source Files/dev_plat/tpos/tpos_timers.o" "./Source Files/dev_plat/fun/fun_data.o" "./Source Files/dev_plat/fun/fun_str.o" "./Source Files/dev_plat/driver/flash/flash_fun.o" "./Source Files/dev_plat/driver/RS232/rs_232.o" "./Source Files/dev_plat/driver/RF/radio_hal.o" "./Source Files/dev_plat/driver/RF/rf_spi.o" "./Source Files/dev_plat/driver/RF/si446x_api_lib.o" "./Source Files/dev_plat/driver/RF/si446x_nirq.o" "./Source Files/dev_plat/driver/R8025T/R8025t.o" "./Source Files/dev_plat/driver/GPS/GPS.o" "./Source Files/dev_plat/driver/GPIO/gpio.o" "./Source Files/app_plat/InitDevice.o" "./Source Files/app_plat/app_task.o" "./Source Files/app_plat/interrupt.o" "./Source Files/app_plat/main.o" "./CMSIS/efm32g/startup_gcc_efm32g.o" "./CMSIS/efm32g/system_efm32g.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
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
