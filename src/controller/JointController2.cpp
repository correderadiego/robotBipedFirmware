/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <controller/JointController2.h>

JointController2::JointController2() {
	loadInitialValues();
}

void JointController2::setAngle(Joint* joint, int angle){
	angle = constrain(angle, joint->getAngleMin(), joint->getAngleMax());

	if(joint->getRotationMode() == Joint::counterClockWise){
		angle = 90 - angle / 10;
	}
}

void JointController2::setAngleDifference(Joint* joint, int angleDifference){
	int angle = constrain(angleDifference + joint->getAngleHome(),	joint->getAngleMin(),joint->getAngleMax());

	if(joint->getRotationMode() == Joint::counterClockWise){
		angle = 90 - angle / 10;
	}
}

void JointController2::dump(Plen* plen){
	Joint** jointVector = plen->getJointVector();
	for(int i = 0; i < plen->getJointSize(); i++){
		jointVector[i]->dump();
	}
}

void JointController2::resetJoints(Plen* plen){
	Joint** jointVector = plen->getJointVector();
	for(int i = 0; i < plen->getJointSize(); i++){
		resetJoint(jointVector[i]);
	}
}

void JointController2::resetJoint(Joint* joint){
	joint->setAngleMax();
	joint->setAngleMin();
	joint->setAngleHome();
	setAngle(joint, joint->getAngleHome());
}

JointController2::JointControllerErrors JointController2::setAngleMin(Joint* joint, int angleMin){
	if (angleMin < ANGLE_MIN || angleMin >= ANGLE_MAX){
		return MIN_VALUE_ERROR;
	}
	joint->setAngleMin(angleMin);
	return NO_ERROR;
}

JointController2::JointControllerErrors JointController2::setAngleMax(Joint* joint, int angleMax){
	if (angleMax > ANGLE_MAX || angleMax <= ANGLE_MIN){
		return MAX_VALUE_ERROR;
	}
	joint->setAngleMax(angleMax);
	return NO_ERROR;
}

JointController2::JointControllerErrors JointController2::setAngleHome(Joint* joint, int angleHome){
	if (angleHome > ANGLE_MAX || angleHome <= ANGLE_MIN){
		return HOME_VALUE_ERROR;
	}
	joint->setAngleHome(angleHome);
	return NO_ERROR;
}

void JointController2::loadInitialValues(){
//	for (char joint_id = 0; joint_id < SUM; joint_id++){
//		setAngle(joint_id, m_SETTINGS[joint_id].HOME);
//	}
}

void JointController2::executeThreadTasks(Plen* plen){
	for (int i = 0; i < plen->getJointSize(); i++){
		//Todo update joint structure
		//plen->getJoint()->getPwm.updatePosition();
	}
}
