/*
 * Eyes.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <bean/Eyes.h>

Eyes::Eyes(Led* led) {
	this->led = led;
}

Led* Eyes::getLed(){
	return this->led;
}

Led::LedStateEnum Eyes::getState(){
	return this->led->getLedState();
}
void Eyes::setState(Led::LedStateEnum state){
	this->led->setLedState(state);
}
