/*
 * PlenBean.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "Plen.h"

Plen::Plen(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter,
			EyeController*	  eyeController,
			Joint* 	joint[],
			int 	jointSize,
			Eyes* 	eyes
		  ) {
	this->jointController 	= jointController;
	this->motionController 	= motionController;
	this->interpreter 		= interpreter;
	this->eyeController		= eyeController;
	this->joint 			= joint;
	this->jointSize 		= jointSize;
	this->eyes				= eyes;
}

Eyes* Plen::getEyes(){
	return this->eyes;
}

JointController* Plen::getJointController(){
	return this->jointController;
}

MotionController* Plen::getMotioncontroller(){
	return this->motionController;
}

Interpreter* Plen::getInterpreter(){
	return this->interpreter;
}

EyeController*	Plen::getEyeController(){
	return this->eyeController;
}
