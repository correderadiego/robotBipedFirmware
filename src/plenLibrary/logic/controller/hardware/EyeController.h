/*
 * EyeController.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_EYECONTROLLER_H_
#define SRC_CONTROLLER_EYECONTROLLER_H_

#include <plenLibrary/logic/bean/Eyes.h>
#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/hardware/LedController.h>

class EyeController {
public:
	EyeController(LedController* ledController);
	void executeThreadTasks(Plen* plen);
private:
	LedController* ledController;
};

#endif /* SRC_CONTROLLER_EYECONTROLLER_H_ */
