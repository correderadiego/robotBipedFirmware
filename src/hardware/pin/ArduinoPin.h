#ifndef SRC_PIN_ARDUINOPIN_H_
#define SRC_PIN_ARDUINOPIN_H_

#include "stdint.h"

#define PIN_VALUE_HIGH 	1
#define PIN_VALUE_LOW 	0

class ArduinoPin {
public:
	ArduinoPin();
	ArduinoPin(uint8_t pin);
	int getPinNumber();
	virtual ~ArduinoPin();
protected:
	uint8_t pinNumber;
};

#endif /* SRC_PIN_ARDUINOPIN_H_ */
