/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER_H_
#define SRC_CONTROLLER_JOINTCONTROLLER_H_

#include <plenLibrary/logic/bean/Plen.h>
#include "hardware/pin/PCA9685PwmController.h"
#include "hardware/pin/pwmPin/PwmPin.h"

class JointController {
public:
	enum JointControllerErrors{
	  MIN_VALUE_ERROR,
	  MAX_VALUE_ERROR,
	  HOME_VALUE_ERROR,
	  NO_ERROR
	};

	JointController(PCA9685PwmController* pca9685PwmController);
	void executeThreadTasks(Plen* plen);
private:
	PCA9685PwmController* pca9685PwmController;
	void moveJoint(Joint* joint);
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER_H_ */
