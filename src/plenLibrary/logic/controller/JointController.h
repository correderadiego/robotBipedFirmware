/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER_H_
#define SRC_CONTROLLER_JOINTCONTROLLER_H_

#include "interfaces/PCA9685PwmControllerInterface.h"
#include "hardware/controller/ExternalFileSystemController.h"
#include <logic/bean/hardware/Joint.h>
#include <logic/bean/Plen.h>
#include "interfaces/PwmPinInterface.h"
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

	JointController(PCA9685PwmControllerInterface* pca9685PwmControllerInterface,
			ExternalFileSystemController* externalFileSystemController);
	ExternalFileSystemController::FileSystemErrors storeJoint(Plen* plen, Joint* joint, int jointIndex);
	ExternalFileSystemController::FileSystemErrors loadJoint(Plen* plen, Joint* joint, int jointIndex);
	void dump(Joint* joint);
	void resetJoint(Joint* joint);
	void updateJointPosition(Joint** jointVector, int jointSize);
private:
	PCA9685PwmControllerInterface* pca9685PwmControllerInterface;
	ExternalFileSystemController* externalFileSystemController;
	void moveJoint(Joint* joint);
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER_H_ */
