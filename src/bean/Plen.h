/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include "Eyes.h"
#include "controller/EyeController.h"
#include "JointController.h"
#include "MotionController.h"
#include "Interpreter.h"
#include "bean/Joint.h"

using namespace PLEN2;

class Plen {
public:
	Plen(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter,
			EyeController*	  eyeController,
			Joint* joint[],
			int jointSize,
			Eyes* eyes
			);

	Eyes* getEyes();
	uint8_t getJointSize();
	JointController*  getJointController();
	MotionController* getMotioncontroller();
	Interpreter*      getInterpreter();
	EyeController*	  getEyeController();

private:
	Joint** joint;
	File* fileMotion;
	File* fileConfiguration;
	File* fileSystemConfiguration;
	int jointSize;
	Eyes* eyes;
	JointController*  jointController;
	MotionController* motionController;
	Interpreter*      interpreter;
	EyeController*	  eyeController;
};

#endif /* SRC_PLEN_H_ */
