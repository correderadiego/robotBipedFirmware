/*
 * PlenFactory.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENFACTORY_H_
#define SRC_PLENFACTORY_H_

#include "bean/Joint.h"
#include "bean/Plen.h"
#include "JointController.h"
#include "MotionController.h"
#include "controller/LedController.h"
#include "Interpreter.h"
#include "hardware/pin/GPIOPin.h"
#include "hardware/pin/PinDefinition.h"

class PlenFactory {
public:
	static Plen* getPlen();
private:

};

#endif /* SRC_PLENFACTORY_H_ */
