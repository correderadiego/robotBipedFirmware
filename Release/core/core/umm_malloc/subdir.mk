################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266/umm_malloc/umm_malloc.c 

C_DEPS += \
./core/core/umm_malloc/umm_malloc.c.d 

AR_OBJ += \
./core/core/umm_malloc/umm_malloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
core/core/umm_malloc/umm_malloc.c.o: /home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266/umm_malloc/umm_malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceMiniPlen/MiniPlen/Release/core" -c -w  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/libraries/Adafruit_PWM_Servo_Driver_Library/1.0.2" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


