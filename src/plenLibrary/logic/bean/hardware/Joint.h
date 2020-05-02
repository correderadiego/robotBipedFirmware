/*
 * Joint.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_JOINT_H_
#define SRC_BEAN_JOINT_H_

#include <ArduinoIncludes.h>
#include "interfaces/PwmPinInterface.h"
#include <utils/Logger.h>

#define ANGLE_MIN      -800
#define	ANGLE_MAX       800
#define ANGLE_NEUTRAL     0

class Joint {
public:
	enum RotationMode{
		clokWise,
		counterClockWise
	};

	struct JointMemory{
		int angleMin;
		int angleMax;
		int angleHome;
	};

	Joint(
			PwmPinInterface* pwmPinInterface = nullptr,
			int homePosition = ANGLE_NEUTRAL,
			Joint::RotationMode rotationMode = RotationMode::clokWise
		  );

	JointMemory* getJointMemory();
	void setAngle(int angle);
	void setAngleHome(int homePosition = ANGLE_NEUTRAL);
	void setAngleMin(int angleMin = ANGLE_MIN);
	void setAngleMax(int angleMax = ANGLE_MAX);
	int getAngle();
	int getAngleHome();
	int getAngleMin();
	int getAngleMax();
	RotationMode getRotationMode();
	PwmPinInterface* getPwmPin();
	void dump();

private:
	enum RotationMode rotationMode;
	int angle;
	JointMemory* jointMemory = new JointMemory();
	PwmPinInterface* pwmPinInterface;
};

#endif /* SRC_BEAN_JOINT_H_ */
