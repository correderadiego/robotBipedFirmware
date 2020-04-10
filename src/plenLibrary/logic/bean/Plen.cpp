/*
 * PlenBean.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/bean/Plen.h>

Plen::Plen(
			Joint* 	joint[],
			int 	jointSize,
			Wifi* wifi,
			Eyes* 	eyes,
			File* fileMotion,
			File* fileConfiguration,
			File* fileSystemConfiguration
		  ) {
	this->joint 			= joint;
	this->jointSize 		= jointSize;
	this->wifi				= wifi;
	this->eyes				= eyes;
	this->fileMotion		= fileMotion;
	this->fileConfiguration	= fileConfiguration;
	this->fileSystemConfiguration = fileSystemConfiguration;
	this->buffer = new Buffer();
}

Eyes* Plen::getEyes(){
	return this->eyes;
}

uint8_t Plen::getJointSize(){
	return this->jointSize;
}

Wifi* Plen::getWifi(){
	return this->wifi;
}

Joint** Plen::getJointVector(){
	return this->joint;
}

File* Plen::getFileConfiguration(){
	return fileConfiguration;
}

File* Plen::getFileSystemConfiguration(){
	return fileSystemConfiguration;
}

Buffer* Plen::getBuffer(){
	return this->buffer;
}
