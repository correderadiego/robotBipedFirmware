/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include "Eyes.h"
#include <FS.h>
#include "logic/bean/Joint.h"
#include "logic/bean/Wifi.h"
#include "logic/bean/Buffer.h"

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
	Eyes* 	getEyes();

	File*	getFileConfiguration();
	File* 	getFileSystemConfiguration();

	Buffer* getBuffer();

private:
	Joint** joint;
	int jointSize;
	Wifi* wifi;
	Eyes* eyes;
	File* fileMotion;
	File* fileConfiguration;
	File* fileSystemConfiguration;
	Buffer* buffer;
};

#endif /* SRC_PLEN_H_ */
