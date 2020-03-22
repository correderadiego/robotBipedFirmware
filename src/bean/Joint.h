/*
 * Joint.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_JOINT_H_
#define SRC_BEAN_JOINT_H_

#include "Arduino.h"

#define ANGLE_MIN      -800
#define	ANGLE_MAX       800
#define ANGLE_NEUTRAL     0

class Joint {
public:
	enum RotationMode{
		clokWise,
		counterClockWise
	};
	Joint(	int homePosition = ANGLE_NEUTRAL,
			Joint::RotationMode rotationMode = clokWise
		  );
	void setAngle(int angle);
	void setAngleHome(int homePosition = ANGLE_NEUTRAL);
	void setAngleMin(int angleMin = ANGLE_MIN);
	void setAngleMax(int angleMax = ANGLE_MAX);
	int getAngle();
	int getAngleHome();
	int getAngleMin();
	int getAngleMax();
	RotationMode getRotationMode();
	void dump();
private:
	enum RotationMode rotationMode;
	int angleMin;
	int angleMax;
	int angleHome;
	int angle;
};

#endif /* SRC_BEAN_JOINT_H_ */
