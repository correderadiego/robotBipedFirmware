#include "Pin.h"

Pin::Pin() {
}

Pin::Pin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
}

int Pin::getPinNumber(){
	return pinNumber;
}

int Pin::getPinValue(){
	return digitalRead(pinNumber);
}

void Pin::setPinValue(uint8_t pinValue){
	digitalWrite(pinNumber, pinValue);
}
