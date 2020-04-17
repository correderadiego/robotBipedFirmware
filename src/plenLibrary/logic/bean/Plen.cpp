/*
 * PlenBean.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/Plen.h>

Plen::Plen(
			Joint* 	joint[],
			int 	jointSize,
			Eyes* 	eyes,
			Buffer* serialBuffer,
			Buffer* socketBuffer,
			File* fileMotion,
			File* fileConfiguration
		  ) {
	this->joint 					= joint;
	this->jointSize 				= jointSize;
	this->eyes						= eyes;
	this->fileMotion				= fileMotion;
	this->fileConfiguration			= fileConfiguration;
	this->serialBuffer 				= serialBuffer;
	this->socketBuffer				= socketBuffer;
}

Eyes* Plen::getEyes(){
	return this->eyes;
}

uint8_t Plen::getJointSize(){
	return this->jointSize;
}

Joint** Plen::getJointVector(){
	return this->joint;
}

File* Plen::getFileConfiguration(){
	return fileConfiguration;
}

Buffer* Plen::getSerialBuffer(){
	return this->serialBuffer;
}

Buffer* Plen::getSocketBuffer(){
	return this->socketBuffer;
}
