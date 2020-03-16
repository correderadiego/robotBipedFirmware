/*
 * PlenBean.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

#include "JointController.h"
#include "Motion.h"
#include "MotionController.h"
#include "Interpreter.h"
#include "Pin.h"
#include "Parser.h"
#include "Protocol.h"
#include "System.h"
#include "Profiler.h"
#include "ExternalFs.h"

using namespace PLEN2;

class Plen {
public:
	Plen(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter
			);
	JointController*  getJointController();
	MotionController* getMotioncontroller();
	Interpreter*      getInterpreter();

private:
	JointController*  jointController;
	MotionController* motionController;
	Interpreter*      interpreter;

};

#endif /* SRC_PLEN_H_ */
