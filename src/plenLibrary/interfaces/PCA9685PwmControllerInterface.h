/*
 * PCA9685PwmControllerInterface.h
 *
 *  Created on: 16 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENLIBRARY_INTERFACES_PCA9685PWMCONTROLLERINTERFACE_H_
#define SRC_PLENLIBRARY_INTERFACES_PCA9685PWMCONTROLLERINTERFACE_H_

#include "stdint.h"

class PCA9685PwmControllerInterface{
public:
	virtual void resetPWMController() = 0;
	virtual void setAngle(uint8_t num, uint16_t duty) = 0;
};



#endif /* SRC_PLENLIBRARY_INTERFACES_PCA9685PWMCONTROLLERINTERFACE_H_ */
