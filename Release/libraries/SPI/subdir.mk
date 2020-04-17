################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI/SPI.cpp 

LINK_OBJ += \
./libraries/SPI/SPI.cpp.o 

CPP_DEPS += \
./libraries/SPI/SPI.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/SPI/SPI.cpp.o: /home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI/SPI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/Release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src/plenLibrary" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1_mini" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/libraries/gdb/1.0.0" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


