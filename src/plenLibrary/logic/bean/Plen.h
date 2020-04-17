/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 Wifi*/

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include <logic/bean/hardware/Buffer.h>
#include <logic/bean/hardware/Eyes.h>
#include <logic/bean/hardware/Joint.h>
#include "ArduinoIncludes.h"

class Plen {
public:
	Plen(
			Joint* joint[],
			int jointSize,
			Eyes* eyes,
			Buffer* serialBuffer,
			Buffer* socketBuffer,
			File* fileMotion,
			File* fileConfiguration
			);

	uint8_t getJointSize();
	Joint** getJointVector();
	Eyes* 	getEyes();

	File*	getFileConfiguration();
	Buffer* getSerialBuffer();
	Buffer* getSocketBuffer();

private:
	Joint** joint;
	int jointSize;
	Eyes* eyes;
	File* fileMotion;
	File* fileConfiguration;
	Buffer* serialBuffer;
	Buffer* socketBuffer;
};

#endif /* SRC_PLEN_H_ */
