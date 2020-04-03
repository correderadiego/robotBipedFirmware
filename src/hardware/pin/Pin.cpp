#include "Pin.h"

Pin::Pin() {}

Pin::Pin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
}

int Pin::getPinNumber(){
	return pinNumber;
}

int Pin::getValue(){
	return digitalRead(pinNumber);
}

void Pin::setValue(uint8_t pinValue){
	digitalWrite(pinNumber, pinValue);
}
