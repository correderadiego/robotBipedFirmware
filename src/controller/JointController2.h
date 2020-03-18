/*
 * JointController2.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_JOINTCONTROLLER2_H_
#define SRC_CONTROLLER_JOINTCONTROLLER2_H_

#include "bean/Plen.h"

class JointController2 {
public:
	JointController2(Plen* plen);
	void executeThreadTasks(Plen* plen);
private:
	void loadInitialValues();
};

#endif /* SRC_CONTROLLER_JOINTCONTROLLER2_H_ */
