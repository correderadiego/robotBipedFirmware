/*
 * LedController.cpp
 *
 *  Created on: 29 dic. 2019
 *      Author: ziash
 */

#include "LedController.h"

LedController::LedController() {
	this->currentMillis 		= millis();
	this->previousMillis		= 0;
}

void LedController::executeThreadTasks(Led* led){
	currentMillis = millis();
	if (currentMillis - previousMillis <= led->getBlinkDelay()){
		return;
	}
	this->blinkLed(led);
	previousMillis = currentMillis;
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
