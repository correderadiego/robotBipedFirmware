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
			Joint* joint[],
			int jointSize,
			Eyes* eyes,
			File* fileMotion,
			File* fileConfiguration
			);

	Eyes* getEyes();
	uint8_t getJointSize();
	Joint** getJointVector();
	File*	getFileConfiguration();
private:
	Joint** joint;
	File* fileMotion;
	File* fileConfiguration;
	int jointSize;
	Eyes* eyes;
};

#endif /* SRC_PLEN_H_ */
