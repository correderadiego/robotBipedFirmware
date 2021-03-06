/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 Wifi*/

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include <logic/bean/hardware/Buffer.h>
#include <logic/bean/hardware/Eyes.h>
#include <logic/bean/hardware/Joint.h>
#include "logic/bean/motion/Motion.h"
#include "ArduinoIncludes.h"

#define EMPTY_VALUE 				"empty"
#define ACCESS_POINT_MODE_STRING 	"AccessPoint"
#define ACCESS_POINT_NAME_STRING 	"Conguito"
#define WIFI_MODE_STRING		 	"Wifi"
#define ACCESS_POINT_IP 			"192.168.4.1"

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

	~Plen();

	uint8_t getJointSize();
	Joint**  getJointVector();
	void  setJointVector(Joint** jointVector);
	Eyes* 	getEyes();

	File*	getFileConfiguration();
	File*	getFileMotion();
	File*	getFileSystem();
	Buffer* getSerialBuffer();
	Buffer* getSocketBuffer();

	Motion* getMotion();
	void setMotion(Motion* motion);

	void  setAccessPointMode(const char* accessPointMode);
	const char* getAccessPointMode();
	void  setAccessPointName(const char* accessPointName);
	const char* getAccessPointName();
	void  setAccessPointPassword(const char* accessPointPassword);
	const char* getAccessPointPassword();
	void  setIp(const char* ip);
	const char* getIp();

private:
	Joint** jointVector;
	int jointSize;
	Eyes* eyes;
	File* fileMotion;
	File* fileConfiguration;
	File* fileSystem;
	Buffer* serialBuffer;
	Buffer* socketBuffer;
	Motion* motion;

	const char* accessPointMode 	= EMPTY_VALUE;
	const char* accessPointName 	= EMPTY_VALUE;
	const char* accessPointPassword = EMPTY_VALUE;
	const char* ip 					= EMPTY_VALUE;
};

#endif /* SRC_PLEN_H_ */
