/*
 * PlenFactory.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENFACTORY_H_
#define SRC_PLENFACTORY_H_

#include "hardware/pin/pwmPin/EmbeddedPwmPin.h"
#include "hardware/pin/pwmPin/PCA9685PwmPin.h"
#include "FS.h"
#include <ESP8266WiFi.h>
#include <hardware/controller/ExternalFileSystemController.h>
#include <hardware/controller/networkController/WifiController.h>
#include <hardware/pin/gpioPin/GPIOPin.h>
#include <logic/bean/hardware/Joint.h>
#include <logic/bean/Plen.h>
#include <logic/controller/Interpreter.h>
#include <logic/controller/JointController.h>
#include <logic/controller/LedController.h>
#include <logic/controller/MotionController.h>
#include <PinDefinition.h>

#define NUMBER_OF_JOINTS 24

#define BUF_SIZE    (1024)

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define MOTION_FILE  "/motion.bin"
#define MOTION_FILE_SIZE 0x200000L

#define CONFIG_FILE  "/joint_cfg.bin"
#define CONFIG_FILE_SIZE 0x1000L

#define HOME_POSITION_LEFT_SHOULDER_PITCH 	-40
#define HOME_POSITION_LEFT_THIGH_YAW		254
#define HOME_POSITION_LEFT_SHOULDER_ROLL 	470
#define HOME_POSITION_LEFT_ELBOW_ROLL		-100
#define HOME_POSITION_LEFT_THIGH_ROLL		-205
#define HOME_POSITION_LEFT_THIGH_PITCH		50
#define HOME_POSITION_LEFT_KNEE_PITCH		445
#define HOME_POSITION_LEFT_FOOT_PITCH		245
#define HOME_POSITION_LEFT_FOOT_ROLL		-75
#define HOME_POSITION_RIGHT_SHOULDER_PITCH 	15
#define HOME_POSITION_RIGHT_THIGH_YAW		-70
#define HOME_POSITION_RIGHT_SHOULDER_ROLL	-390
#define HOME_POSITION_RIGHT_ELBOW_ROLL		250
#define HOME_POSITION_RIGHT_THIGH_ROLL		195
#define HOME_POSITION_RIGHT_THIGH_PITCH		-105
#define HOME_POSITION_RIGHT_KNEE_PITCH		-510
#define HOME_POSITION_RIGHT_FOOT_PITCH		-305
#define HOME_POSITION_RIGHT_FOOT_ROLL		60

class PlenFactory {
public:
	Plen* getPlen();
private:
	void openFiles (File fileMotion, File fileConfiguration);
	Joint* joint[24] = {};
};

#endif /* SRC_PLENFACTORY_H_ */
