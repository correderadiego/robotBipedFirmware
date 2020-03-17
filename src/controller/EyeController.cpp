/*
 * EyeController.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <controller/EyeController.h>

EyeController::EyeController(LedController* ledController) {
	this->ledController = ledController;
}

void EyeController::executeThreadTasks(Eyes* eyes){
	this->ledController->executeThreadTasks(eyes->getLed());
}
