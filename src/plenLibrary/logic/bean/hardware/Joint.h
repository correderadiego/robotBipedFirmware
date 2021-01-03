/*
 * Joint.h
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_JOINT_H_
#define SRC_BEAN_JOINT_H_

#include <ArduinoIncludes.h>
#include "interfaces/PwmPinInterface.h"
#include <utils/Logger.h>
#include "../../../Configuration.h"

class Joint {
public:
	enum RotationMode{
		clockWise,
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
			Joint::RotationMode rotationMode = RotationMode::clockWise,
			bool enabled = true
		  );

	JointMemory* getJointMemory();
	void setAngle(int angle);
	void setAngleHome(int homePosition = ANGLE_NEUTRAL);
	void setAngleMin(int angleMin = ANGLE_MIN);
	void setAngleMax(int angleMax = ANGLE_MAX);
	int getDefaultAngleHome();
	int getAngle();
	int getAngleHome();
	int getAngleMin();
	int getAngleMax();
	RotationMode getRotationMode();
	PwmPinInterface* getPwmPin();
	bool isEnabled();
	void setEnabled(bool enabled);

private:
	enum RotationMode rotationMode;
	int angle;
	int defaultHome;
	JointMemory jointMemory;
	PwmPinInterface* pwmPinInterface;
	bool enabled;
};

#endif /* SRC_BEAN_JOINT_H_ */
