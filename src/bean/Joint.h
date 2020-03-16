/*
 * Joint.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_JOINT_H_
#define SRC_BEAN_JOINT_H_

#define ANGLE_MIN      -800
#define	ANGLE_MAX       800
#define ANGLE_NEUTRAL     0

class Joint {
public:
	Joint(int homePosition = ANGLE_NEUTRAL);
	void setHomePosition(int homePosition = ANGLE_NEUTRAL);
private:
	int angleMin;
	int angleMax;
	int homePosition;
};

#endif /* SRC_BEAN_JOINT_H_ */
