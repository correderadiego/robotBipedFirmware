/*
 * Led.cpp
 *
 *  Created on: 7 dic. 2019
 *      Author: ziash
 */

#include "Led.h"

Led::Led(GPIOPin* gpioPin) {
	this->gpioPin 			= gpioPin;
	this->ledStateEnum  	= switchOff;
	this->ledBlinkStateEnum = switchBlinkOff;
	this->ledBlinkDelay		= DEFAULT_BLINK_DELAY;
}

Led::LedStateEnum Led::getLedState(){
	return this->ledStateEnum;
}

void Led::setLedState(LedStateEnum ledStateEnum){
	if(ledStateEnum == LedStateEnum::switchOn){
		switchOnLed();
	}

	if(ledStateEnum == LedStateEnum::switchOff){
		switchOffLed();
	}

	this->ledStateEnum = ledStateEnum;
}

Led::LedBlinkStateEnum Led::getBlinLedState(){
	return this->ledBlinkStateEnum;
}

void Led::setBlinkLedState(LedBlinkStateEnum ledBlinkStateEnum){
	if(ledBlinkStateEnum == LedBlinkStateEnum::switchBlinkOff){
		switchOnLed();
	}

	if(ledBlinkStateEnum == LedBlinkStateEnum::switchBlinkOn){
		switchOffLed();
	}

	this->ledBlinkStateEnum = ledBlinkStateEnum;
}

void Led::switchOnLed(){
	gpioPin->setPinValue(HIGH);
}

void Led::switchOffLed(){
	gpioPin->setPinValue(LOW);
}

unsigned long Led::getBlinkDelay(){
	return this->ledBlinkDelay;
}

void Led::setBlinkDelay(unsigned long ledBlinkDelay){
	this->ledBlinkDelay = ledBlinkDelay;
}
