################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
GLOBAL_INTERRUPT.lss \

FLASH_IMAGE += \
GLOBAL_INTERRUPT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: GLOBAL_INTERRUPT.elf secondary-outputs

# Tool invocations
GLOBAL_INTERRUPT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,GLOBAL_INTERRUPT.map -mmcu=atmega32 -o "GLOBAL_INTERRUPT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GLOBAL_INTERRUPT.lss: GLOBAL_INTERRUPT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GLOBAL_INTERRUPT.elf  >"GLOBAL_INTERRUPT.lss"
	@echo 'Finished building: $@'
	@echo ' '

GLOBAL_INTERRUPT.hex: GLOBAL_INTERRUPT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex GLOBAL_INTERRUPT.elf  "GLOBAL_INTERRUPT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GLOBAL_INTERRUPT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 GLOBAL_INTERRUPT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) GLOBAL_INTERRUPT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
