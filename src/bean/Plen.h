/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include "Eyes.h"
#include "controller/EyeController.h"
#include "JointController.h"
#include "MotionController.h"
#include "Interpreter.h"
#include "bean/Joint.h"
#include "bean/Wifi.h"

using namespace PLEN2;

class Plen {
public:
	Plen(
			Joint* joint[],
			int jointSize,
			Wifi* wifi,
			Eyes* eyes,
			File* fileMotion,
			File* fileConfiguration,
			File* fileSystemconfiguration
			);

	uint8_t getJointSize();
	Joint** getJointVector();
	Wifi*	getWifi();
	Eyes* getEyes();

	File*	getFileConfiguration();
	File* 	getFileSystemConfiguration();

private:
	Joint** joint;
	int jointSize;
	Wifi* wifi;
	Eyes* eyes;
	File* fileMotion;
	File* fileConfiguration;
	File* fileSystemConfiguration;
};

#endif /* SRC_PLEN_H_ */
