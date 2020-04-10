/*
 * PlenFactory.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENFACTORY_H_
#define SRC_PLENFACTORY_H_

#include "controller/hardware/ExternalFileSystemController.h"
#include "bean/Joint.h"
#include "bean/Plen.h"
#include "controller/hardware/JointController.h"
#include "controller/MotionController.h"
#include "controller/hardware/LedController.h"
#include "controller/Interpreter.h"
#include "hardware/pin/GPIOPin.h"
#include "hardware/pin/pwmPin/EmbeddedPwmPin.h"
#include "hardware/pin/pwmPin/PCA9685PwmPin.h"
#include "hardware/pin/PinDefinition.h"
#include "FS.h"
#include <ESP8266WiFi.h>

#define NUMBER_OF_JOINTS 24

#define BUF_SIZE    (1024)

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define DEFAULT_HTTP_PORT		80
#define DEFAULT_WIFI_SOCKET_PORT 23

#define PIN_LEFT_SHOULDER_PITCH 	1
#define PIN_LEFT_THIGH_YAW			2
#define PIN_LEFT_SHOULDER_ROLL 		3
#define PIN_LEFT_ELBOW_ROLL			4
#define PIN_LEFT_THIGH_ROLL			5
#define PIN_LEFT_THIGH_PITCH		6
#define PIN_LEFT_KNEE_PITCH			7
#define PIN_LEFT_FOOT_PITCH			8
#define PIN_LEFT_FOOT_ROLL			9
#define PIN_RIGHT_SHOULDER_PITCH 	10
#define PIN_RIGHT_THIGH_YAW			11
#define PIN_RIGHT_SHOULDER_ROLl		12
#define PIN_RIGHT_ELBOW_ROLL		13
#define PIN_RIGHT_THIGH_ROLL		14
#define PIN_RIGHT_THIGH_PITCH		15
#define PIN_RIGHT_KNEE_PITCH		16
#define PIN_RIGHT_FOOT_PITCH		17
#define PIN_RIGHT_FOOT_ROLL			18

class PlenFactory {
public:
	Plen* getPlen();
private:
	void openFiles (File fileMotion, File fileConfiguration, File fileSystemConfiguration);
	Wifi* createWifi(File* fileSystemConfiguration);
	Wifi* createDefaultWifi();
	Joint* joint[24] = {};
};

#endif /* SRC_PLENFACTORY_H_ */
