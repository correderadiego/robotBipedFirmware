################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/utils/subdir.mk
-include src/hardware/pin/subdir.mk
-include src/hardware/led/subdir.mk
-include src/hardware/subdir.mk
-include src/controller/parser/subdir.mk
-include src/controller/subdir.mk
-include src/bean/commands/subdir.mk
-include src/bean/subdir.mk
-include src/subdir.mk
-include libraries/gdb/subdir.mk
-include libraries/Wire/subdir.mk
-include libraries/Ticker/subdir.mk
-include libraries/Servo/src/subdir.mk
-include libraries/SPI/subdir.mk
-include libraries/ESP8266mDNS/subdir.mk
-include libraries/ESP8266WiFi/src/subdir.mk
-include libraries/ESP8266WebServer/src/detail/subdir.mk
-include libraries/ESP8266WebServer/src/subdir.mk
-include libraries/ESP8266HTTPUpdateServer/src/subdir.mk
-include libraries/Adafruit_PWM_Servo_Driver_Library/subdir.mk
-include core/core/umm_malloc/subdir.mk
-include core/core/spiffs/subdir.mk
-include core/core/libb64/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/ziash/workspaceEsp8266/MiniPlen/Release/arduino.ar \

ELF += \
MiniPlen.elf \

HEX += \
MiniPlen.hex \


# All Target
all: MiniPlen

# Tool invocations
MiniPlen: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-size" -A "/home/ziash/workspaceEsp8266/MiniPlen/Release/MiniPlen.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/ziash/workspaceEsp8266/MiniPlen/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "/home/ziash/workspaceEsp8266/MiniPlen/Release/arduino.ar"    /home/ziash/workspaceEsp8266/MiniPlen/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

MiniPlen.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	${A.RECIPE.HOOKS.LINKING.PRELINK.1.PATTERN}
	${A.RECIPE.C.COMBINE.PATTERN.1}  $(LINK_OBJ) ${A.RECIPE.C.COMBINE.PATTERN.2} ${A.ARCHIVE_FILE_PATH} ${A.RECIPE.C.COMBINE.PATTERN.3} ${JANTJE.EXTRA.ALL} ${JANTJE.EXTRA.LINK}${A.JANTJE.POST.LINK}
	@echo 'Finished building: $@'
	@echo ' '

MiniPlen.hex: $(ELF)
	@echo 'Do all objcopy commands'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/esptool/0.4.13/esptool" -eo "/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/bootloaders/eboot/eboot.elf" -bo "/home/ziash/workspaceEsp8266/MiniPlen/Release/MiniPlen.bin" -bm dio -bf 40 -bz 4M -bs .text -bp 4096 -ec -eo "/home/ziash/workspaceEsp8266/MiniPlen/Release/MiniPlen.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
