/*
 * GPIOPinInterface.h
 *
 *  Created on: 11 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_PLENLIBRARY_INTERFACES_GPIOPININTERFACE_H_
#define SRC_PLENLIBRARY_INTERFACES_GPIOPININTERFACE_H_

#include "stdint.h"

class GPIOPinInterface{

#define HIGH 0x1
#define LOW  0x0

public:
	virtual int getPinValue () = 0;
	virtual void setPinValue(uint8_t value) = 0;
	virtual void pullUpMode () = 0;
};

#endif /* SRC_PLENLIBRARY_INTERFACES_GPIOPININTERFACE_H_ */
