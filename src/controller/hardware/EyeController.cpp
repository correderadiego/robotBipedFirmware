/*
 * EyeController.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "EyeController.h"

EyeController::EyeController(LedController* ledController) {
	this->ledController = ledController;
}

void EyeController::executeThreadTasks(Plen* plen){
	this->ledController->executeThreadTasks(plen->getEyes()->getLed());
}