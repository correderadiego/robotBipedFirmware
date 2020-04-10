/*
 * LedController.h
 *
 *  Created on: 29 dic. 2019
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_
#define SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_

#include "hardware/led/Led.h"

class LedController {
public:
	#define LED_CONTROLLER_EXECUTION_DELAY 50
	LedController();
	void executeThreadTasks(Led* led);
private:
	unsigned long currentMillis;
	unsigned long previousMillis;
	void blinkLed(Led* led);
};

#endif /* SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_ */
