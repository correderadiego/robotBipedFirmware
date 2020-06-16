/*
 * LedController.cpp
 *
 *  Created on: 29 dic. 2019
 *      Author: ziash
 */

#include <logic/controller/LedController.h>

LedController::LedController(int executionDelayMilliSeconds) {
	this->setExecutionDelayMilliSeconds(executionDelayMilliSeconds);
}

void LedController::executeThreadTasks(Led* led){
	if(executeTask()){
		this->blinkLed(led);
	}
}

void LedController::blinkLed(Led* led){
	if(led->getLedState() != Led::LedStateEnum::blink){
		return;
	}

	if(led->getBlinLedState() == Led::LedBlinkStateEnum::switchBlinkOn){
		led->setBlinkLedState(Led::LedBlinkStateEnum::switchBlinkOff);
		return;
	}

	if(led->getBlinLedState() == Led::LedBlinkStateEnum::switchBlinkOff){
		led->setBlinkLedState(Led::LedBlinkStateEnum::switchBlinkOn);
		return;
	}
}
