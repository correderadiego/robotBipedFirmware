/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER_H_
#define SRC_CONTROLLER_JOINTCONTROLLER_H_

#include "interfaces/PCA9685PwmControllerInterface.h"
#include <logic/bean/hardware/Joint.h>
#include <logic/bean/Plen.h>
#include "interfaces/PwmPinInterface.h"

class JointController {
public:
	enum JointControllerErrors{
	  MIN_VALUE_ERROR,
	  MAX_VALUE_ERROR,
	  HOME_VALUE_ERROR,
	  NO_ERROR
	};

	JointController(PCA9685PwmControllerInterface* pca9685PwmControllerInterface);
	void executeThreadTasks(Plen* plen);
private:
	PCA9685PwmControllerInterface* pca9685PwmControllerInterface;
	void moveJoint(Joint* joint);
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER_H_ */
