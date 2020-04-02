/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER_H_
#define SRC_CONTROLLER_JOINTCONTROLLER_H_

#include "bean/Plen.h"

class JointController {
public:
	enum JointControllerErrors{
	  MIN_VALUE_ERROR,
	  MAX_VALUE_ERROR,
	  HOME_VALUE_ERROR,
	  NO_ERROR
	};

	JointController();
	void resetJoints(Plen* plen);
	void loadInitialValues();
	void dump(Plen* plen);
	JointController::JointControllerErrors setAngleMin (Joint* joint, int minAngle);
	JointController::JointControllerErrors setAngleMax (Joint* joint, int maxAngle);
	JointController::JointControllerErrors setAngleHome(Joint* joint, int homeAngle);

	void setAngle(Joint* joint, int angle);
	void setAngleDifference(Joint* joint, int angleDifference);
	void executeThreadTasks(Plen* plen);
private:

	void resetJoint(Joint* joint);
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER_H_ */
