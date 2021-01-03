/*
 * PCA9685PwmControllerInterface.h
 *
 *  Created on: 16 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_PLENLIBRARY_INTERFACES_PWMCONTROLLERINTERFACE_H_
#define SRC_PLENLIBRARY_INTERFACES_PWMCONTROLLERINTERFACE_H_

#include "stdint.h"
#include <logic/bean/hardware/Joint.h>

class PwmControllerInterface{
public:
	virtual void setValue(Joint::RotationMode rotationMode, uint8_t num, uint16_t duty) = 0;
};



#endif /* SRC_PLENLIBRARY_INTERFACES_PWMCONTROLLERINTERFACE_H_ */
