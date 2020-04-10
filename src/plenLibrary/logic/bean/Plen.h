/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include <FS.h>
#include <plenLibrary/logic/bean/Buffer.h>
#include <plenLibrary/logic/bean/Eyes.h>
#include <plenLibrary/logic/bean/Joint.h>
#include <plenLibrary/logic/bean/Wifi.h>

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
