/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include "JointController.h"
#include "MotionController.h"
#include "Interpreter.h"
#include "bean/Joint.h"

using namespace PLEN2;

#define NUMBER_OF_JOINTS 24

class Plen {
public:
	Plen(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter,
			Joint* joint[],
			int jointSize
			);
	JointController*  getJointController();
	MotionController* getMotioncontroller();
	Interpreter*      getInterpreter();

private:
	Joint** joint;
	int jointSize;
	JointController*  jointController;
	MotionController* motionController;
	Interpreter*      interpreter;

};

#endif /* SRC_PLEN_H_ */
