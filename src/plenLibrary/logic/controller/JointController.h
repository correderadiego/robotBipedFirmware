/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER_H_
#define SRC_CONTROLLER_JOINTCONTROLLER_H_

#include <interfaces/PwmControllerInterface.h>
#include "hardware/controller/ExternalFileSystemController.h"
#include <logic/bean/hardware/Joint.h>
#include <logic/bean/Plen.h>
#include "interfaces/PwmPinInterface.h"
#include "../../Configuration.h"
#include "stddef.h"


class JointController {
public:
	enum JointControllerErrors{
	  MIN_VALUE_ERROR,
	  MAX_VALUE_ERROR,
	  HOME_VALUE_ERROR,
	  NO_ERROR
	};

	ExternalFileSystemController* getExternalFileSystemController();

	JointController(
			PwmControllerInterface* pca9685PwmControllerInterface,
			ExternalFileSystemController* externalFileSystemController);
	ExternalFileSystemController::FileSystemErrors storeJoint(Plen* plen, Joint* joint, int jointIndex);
	ExternalFileSystemController::FileSystemErrors loadJoint(Plen* plen, Joint* joint, int jointIndex);
	void dump(Joint* joint);
	void resetJoint(Joint* joint);
	void updateJointPosition(Joint** jointVector, int jointSize);
	int getPCA9685PwmValue(Joint* joint);
	int getEmbeddedPwmValue(Joint* joint);
	void moveJoint(Joint* joint);
private:
	PwmControllerInterface* pca9685PwmController;
	ExternalFileSystemController* externalFileSystemController;
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER_H_ */
