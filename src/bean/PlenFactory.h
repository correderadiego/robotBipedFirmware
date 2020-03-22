/*
 * PlenFactory.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENFACTORY_H_
#define SRC_PLENFACTORY_H_

#include <controller/ExternalFileSystemController.h>
#include "bean/Joint.h"
#include "bean/Plen.h"
#include "JointController.h"
#include "MotionController.h"
#include "controller/LedController.h"
#include "Interpreter.h"
#include "hardware/pin/GPIOPin.h"
#include "hardware/pin/PinDefinition.h"
#include "FS.h"

#define NUMBER_OF_JOINTS 24

#define BUF_SIZE    (1024)

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define DEFAULT_HTTP_PORT		80

class PlenFactory {
public:
	Plen* getPlen();
private:
	void openFiles (File fileMotion, File fileConfiguration, File fileSystemConfiguration);
	Wifi* createWifi(File* fileSystemConfiguration);
	Wifi* createDefaultWifi();
};

#endif /* SRC_PLENFACTORY_H_ */
