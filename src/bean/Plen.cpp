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
			Interpreter*      interpreter
		  ) {
	this->jointController 	= jointController;
	this->motionController 	= motionController;
	this->interpreter 		= interpreter;
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
