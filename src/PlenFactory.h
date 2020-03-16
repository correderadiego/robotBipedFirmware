/*
 * PlenFactory.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENFACTORY_H_
#define SRC_PLENFACTORY_H_

#include "Plen.h"

class PlenFactory {
public:
	static Plen* getPlen();

private:
	static JointController*  	jointController;
	static MotionController* 	motionController;
	static Interpreter*      	interpreter;

};

#endif /* SRC_PLENFACTORY_H_ */
