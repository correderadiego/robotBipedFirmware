################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AccelerationGyroSensor.cpp \
../src/ExternalFS.cpp \
../src/Interpreter.cpp \
../src/JointController.cpp \
../src/Motion.cpp \
../src/MotionController.cpp \
../src/Parser.cpp \
../src/Profiler.cpp \
../src/Protocol.cpp \
../src/Soul.cpp \
../src/System.cpp 

LINK_OBJ += \
./src/AccelerationGyroSensor.cpp.o \
./src/ExternalFS.cpp.o \
./src/Interpreter.cpp.o \
./src/JointController.cpp.o \
./src/Motion.cpp.o \
./src/MotionController.cpp.o \
./src/Parser.cpp.o \
./src/Profiler.cpp.o \
./src/Protocol.cpp.o \
./src/Soul.cpp.o \
./src/System.cpp.o 

CPP_DEPS += \
./src/AccelerationGyroSensor.cpp.d \
./src/ExternalFS.cpp.d \
./src/Interpreter.cpp.d \
./src/JointController.cpp.d \
./src/Motion.cpp.d \
./src/MotionController.cpp.d \
./src/Parser.cpp.d \
./src/Profiler.cpp.d \
./src/Protocol.cpp.d \
./src/Soul.cpp.d \
./src/System.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/AccelerationGyroSensor.cpp.o: ../src/AccelerationGyroSensor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/ExternalFS.cpp.o: ../src/ExternalFS.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Interpreter.cpp.o: ../src/Interpreter.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/JointController.cpp.o: ../src/JointController.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Motion.cpp.o: ../src/Motion.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/MotionController.cpp.o: ../src/MotionController.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Parser.cpp.o: ../src/Parser.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Profiler.cpp.o: ../src/Profiler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Protocol.cpp.o: ../src/Protocol.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/Soul.cpp.o: ../src/Soul.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

src/System.cpp.o: ../src/System.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-I/home/ziash/eclipse/eclipse//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ziash/workspaceEsp8266/MiniPlen/esp-release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1R1 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_WEMOS_D1R1"   -DESP8266   -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/cores/esp8266" -I"/home/ziash/workspaceEsp8266/MiniPlen/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/variants/d1" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266mDNS" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WiFi/src" -I"/home/ziash/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266HTTPUpdateServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/ESP8266WebServer/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Servo/src" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Ticker" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/Wire" -I"/home/ziash/eclipse/eclipse/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/libraries/SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

