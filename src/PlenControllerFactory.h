/*
 * PlenControllerFactory.h
 *
 *  Created on: 19 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_PLENCONTROLLERFACTORY_H_
#define SRC_CONTROLLER_PLENCONTROLLERFACTORY_H_

#include <logic/controller/PlenController.h>
#include "logic/controller/HeaderController.h"
#include "logic/controller/FrameController.h"
#include "hardware/controller/PCA9685PwmController.h"

class PlenControllerFactory {
public:
	PlenController* getPlenController(ExternalFileSystemController* externalFileSystemController);
};

#endif /* SRC_CONTROLLER_PLENCONTROLLERFACTORY_H_ */
