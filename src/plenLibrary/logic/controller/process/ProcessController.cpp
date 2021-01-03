/*
 * CommandController.cpp
 *
 *  Created on: 28 mar. 2020
 *      Author: Diego
 */

#include "ProcessController.h"

ProcessController::ProcessController(JointController* jointController, MotionController* motionController) {
		this->jointController = jointController;
		this->motionController = motionController;
		commandController[0] = new ProcessControllerControllerCommand(jointController, motionController);
		commandController[1] = new ProcessControllerInterpreterCommand();
		commandController[2] = new ProcessControllerSetterCommand(jointController, motionController);
		commandController[3] = new ProcessControllerGetterCommand(jointController, motionController);
}

ProcessController::~ProcessController() {
	delete commandController[0];
	delete commandController[1];
	delete commandController[2];
	delete commandController[3];
}

ProcessControllerInterface::CommandControllerErrors ProcessController::process(Plen* plen, CommandInterface* command){
	for (unsigned int i= 0; i < sizeof(commandController)/sizeof(commandController[0]); i++) {
		if (commandController[i]->match(command)) {
			return commandController[i]->process(plen, command);
		}
	}

	return ProcessControllerInterface::UNKNOWN_COMMAND;
}
