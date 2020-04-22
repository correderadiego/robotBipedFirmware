/*
 * RunnableController.cpp
 *
 *  Created on: 17 abr. 2020
 *      Author: ziash
 */

#include <hardware/controller/RunnableController.h>

RunnableController::RunnableController() {}


RunnableController::RunnableController(int executionDelayMilliSeconds) {
	this->executionDelayMilliSeconds = executionDelayMilliSeconds;
}

bool RunnableController::executeTask(){
	currentMillis = millis();
	if (currentMillis - previousMillis <= executionDelayMilliSeconds){
		return false;
	}
	previousMillis = currentMillis;
	return true;
}

