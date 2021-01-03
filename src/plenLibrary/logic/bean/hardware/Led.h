#ifndef SRC_LED_H_
#define SRC_LED_H_

#include "interfaces/GPIOPinInterface.h"

class Led {

#define DEFAULT_BLINK_DELAY	200

public:
	Led(GPIOPinInterface* gpioPin);
	enum LedStateEnum{
		switchOn, switchOff, blink
	};
	enum LedBlinkStateEnum{
		switchBlinkOn, switchBlinkOff
	};
	void setLedState(LedStateEnum ledStateEnum);
	LedStateEnum getLedState();
	void setBlinkLedState(LedBlinkStateEnum ledBlinkStateEnum);
	LedBlinkStateEnum getBlinLedState();
	void setBlinkDelay(unsigned long ledBlinkDelay);
	unsigned long getBlinkDelay();

private:
	LedStateEnum 		ledStateEnum;
	LedBlinkStateEnum 	ledBlinkStateEnum;
	unsigned long 		ledBlinkDelay;
	GPIOPinInterface* 	gpioPinInterface;
	void switchOnLed();
	void switchOffLed();
};

#endif /* SRC_LED_H_ */
