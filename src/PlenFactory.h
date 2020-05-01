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
#include "Configuration.h"

#define BUF_SIZE    (1024)

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

class PlenFactory {
public:
	Plen* getPlen(ExternalFileSystemController* externalFsController);
private:
	Joint* joint[24] = {};

	void openFiles (ExternalFileSystemController* externalFsController,
			File* fileMotion, File* fileConfiguration, File* fileSystem);
	void createFilesIfDontExist(ExternalFileSystemController* externalFsController);
};

#endif /* SRC_PLENFACTORY_H_ */
