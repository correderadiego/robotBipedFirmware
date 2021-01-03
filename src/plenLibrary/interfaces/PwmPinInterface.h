/*
 * PwmPinInterface.h
 *
 *  Created on: 11 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_PLENLIBRARY_INTERFACES_PWMPININTERFACE_H_
#define SRC_PLENLIBRARY_INTERFACES_PWMPININTERFACE_H_

#include "stdint.h"

class PwmPinInterface{
public:
	enum PwmPinType{
		EMBEDDED_PWM_PIN,
		PAC9685_PWM_PIN
	};
	virtual void setValue(int rotationMode, uint8_t duty) = 0;
	virtual PwmPinType getPwmPinType()  = 0;
	virtual uint8_t getPinNumber()      = 0;
};

#endif /* SRC_PLENLIBRARY_INTERFACES_PWMPININTERFACE_H_ */
