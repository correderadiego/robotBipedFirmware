/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER2_H_
#define SRC_CONTROLLER_JOINTCONTROLLER2_H_

#include "bean/Plen.h"

class JointController2 {
public:
	enum JointControllerErrors{
	  MIN_VALUE_ERROR,
	  MAX_VALUE_ERROR,
	  HOME_VALUE_ERROR,
	  NO_ERROR
	};

	JointController2();
	void resetJoints(Plen* plen);
	void loadInitialValues();
	void dump(Plen* plen);
	JointController2::JointControllerErrors setAngleMin (Joint* joint, int minAngle);
	JointController2::JointControllerErrors setAngleMax (Joint* joint, int maxAngle);
	JointController2::JointControllerErrors setAngleHome(Joint* joint, int homeAngle);

	void setAngle(Joint* joint, int angle);
	void setAngleDifference(Joint* joint, int angleDifference);
	void executeThreadTasks(Plen* plen);
private:

	void resetJoint(Joint* joint);
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER2_H_ */
