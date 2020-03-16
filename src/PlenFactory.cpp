/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <PlenFactory.h>

Plen* PlenFactory::getPlen() {
	JointController* jointController = new JointController();
	MotionController* motionController= new MotionController(*jointController);
	Interpreter* interpreter 	= new Interpreter(*motionController);

	return new Plen(jointController, motionController, interpreter);
}


