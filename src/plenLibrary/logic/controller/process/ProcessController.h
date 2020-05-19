	/*
 * CommandController.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_

#include <logic/controller/process/ProcessControllerControllerCommand.h>
#include <logic/controller/process/ProcessControllerGetterCommand.h>
#include <logic/controller/process/ProcessControllerInterface.h>
#include <logic/controller/process/ProcessControllerInterpreterCommand.h>
#include <logic/controller/process/ProcessControllerSetterCommand.h>
#include "logic/controller/JointController.h"
#include "logic/controller/MotionController.h"

#define COMMAND_CONTROLLER_VECTOR_SIZE	 4
class ProcessController {
	public:
		ProcessController(JointController* jointController, MotionController* motionController);
		ProcessControllerInterface::CommandControllerErrors process(Plen* plen, CommandInterface* command);

		ProcessControllerInterface* commandController[COMMAND_CONTROLLER_VECTOR_SIZE];
	private:
		JointController* jointController;
		MotionController* motionController;
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_ */
