/*
 * RunnableController.cpp
 *
 *  Created on: 17 abr. 2020
 *      Author: ziash
 */

#include <hardware/controller/RunnableController.h>

RunnableController::RunnableController() {
	this->currentMillis   = 0;
	this->previousMillis  = 0;
	this->executionDelayMilliSeconds = DEFAULT_EXECUTION_DELAY;
}

RunnableController::RunnableController(int executionDelayMilliSeconds) {
	this->currentMillis   = 0;
	this->previousMillis  = 0;
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

void RunnableController::setExecutionDelayMilliSeconds(int executionDelayMilliSeconds){
	this->executionDelayMilliSeconds = executionDelayMilliSeconds;
}
