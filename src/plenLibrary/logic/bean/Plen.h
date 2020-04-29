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

#define EMPTY_VALUE "empty"

class Plen {
public:
	Plen(
			Joint **joint,
			int jointSize,
			Eyes* eyes,
			Buffer* serialBuffer,
			Buffer* socketBuffer,
			File* fileMotion,
			File* fileConfiguration,
			File* fileSystem
			);

	uint8_t getJointSize();
	Joint**  getJointVector();
	Eyes* 	getEyes();

	File*	getFileConfiguration();
	File*	getFileMotion();
	File*	getFileSystem();
	Buffer* getSerialBuffer();
	Buffer* getSocketBuffer();

	void  setAccessPointMode(const char* accessPointMode);
	const char* getAccessPointMode();
	void  setAccessPointName(const char* accessPointName);
	const char* getAccessPointName();
	void  setAccessPointPassword(const char* accessPointPassword);
	const char* getAccessPointPassword();
	void  setIp(const char* ip);
	const char* getIp();

private:
	Joint** joint;
	int jointSize;
	Eyes* eyes;
	File* fileMotion;
	File* fileConfiguration;
	File* fileSystem;
	Buffer* serialBuffer;
	Buffer* socketBuffer;

	const char* accessPointMode 	= EMPTY_VALUE;
	const char* accessPointName 	= EMPTY_VALUE;
	const char* accessPointPassword = EMPTY_VALUE;
	const char* ip 					= EMPTY_VALUE;
};

#endif /* SRC_PLEN_H_ */
