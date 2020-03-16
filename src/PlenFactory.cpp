/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <PlenFactory.h>

Plen* PlenFactory::getPlen() {
	jointController = new JointController();
	motionController= new MotionController(*jointController);
	interpreter 	= new Interpreter(*motionController);
	return new Plen(jointController, motionController, interpreter);
}


