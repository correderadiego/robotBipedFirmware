/*
 * LedController.h
 *
 *  Created on: 29 dic. 2019
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_
#define SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_

#include <logic/bean/hardware/Led.h>
#include "Arduino.h"
#include "hardware/controller/RunnableController.h"

class LedController : public RunnableController {
public:
	#define LED_CONTROLLER_EXECUTION_DELAY 50
	LedController(int executionDelayMilliSeconds = LED_CONTROLLER_EXECUTION_DELAY);
	void executeThreadTasks(Led* led);
private:
	void blinkLed(Led* led);
};

#endif /* SRC_CONTROLLER_HARDWARECONTROLLER_LEDCONTROLLER_H_ */
