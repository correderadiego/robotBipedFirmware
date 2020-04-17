/*
 * EyeController.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_EYECONTROLLER_H_
#define SRC_CONTROLLER_EYECONTROLLER_H_

#include <logic/bean/hardware/Eyes.h>
#include <logic/bean/Plen.h>
#include <logic/controller/LedController.h>

class EyeController {
public:
	EyeController(LedController* ledController);
	void executeThreadTasks(Plen* plen);
private:
	LedController* ledController;
};

#endif /* SRC_CONTROLLER_EYECONTROLLER_H_ */
