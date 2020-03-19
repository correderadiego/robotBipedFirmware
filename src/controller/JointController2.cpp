/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <controller/JointController2.h>

JointController2::JointController2(Plen* plen) {
	loadInitialValues();
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
