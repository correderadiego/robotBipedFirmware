/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <controller/JointController2.h>

JointController2::JointController2(Plen* plen) {
}

void JointController2::loadInitialValues(){
	/**
	if (ExternalFs::readByte(INIT_FLAG_ADDRESS(), fileConfiguration) != INIT_FLAG_VALUE()){
			ExternalFs::writeByte(INIT_FLAG_ADDRESS(), INIT_FLAG_VALUE(), fileConfiguration);
	        ExternalFs::write(SETTINGS_HEAD_ADDRESS(), sizeof(m_SETTINGS), filler, fileConfiguration);
			System::debugSerial().println(F("reset config\n"));
		}else{
			ExternalFs::read(SETTINGS_HEAD_ADDRESS(), sizeof(m_SETTINGS), filler, fileConfiguration);
			System::debugSerial().println(F("read config"));
		}

		for (char joint_id = 0; joint_id < SUM; joint_id++){
			setAngle(joint_id, m_SETTINGS[joint_id].HOME);
		}
		**/
}

void JointController2::executeThreadTasks(Plen* plen){
	for (int i = 0; i < plen->getJointSize(); i++){
		//Todo update joint structure
		//plen->getJoint()->getPwm.updatePosition();
	}
}
