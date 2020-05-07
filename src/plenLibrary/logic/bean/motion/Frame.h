/*
 * Frame.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_FRAME_H_
#define SRC_BEAN_MOTION_FRAME_H_

#include "Configuration.h"

class Frame {
public:
	Frame();
	Frame(
			unsigned int slot,
			unsigned int frameIndex,
			unsigned int transitionTimems,
			int*         jointAngle,
			int 		 numberOfJoints
			);

	unsigned int getSlot();
	unsigned int getFrameIndex();
	unsigned int getTransitionTime();
	int* getJointAngle();

	void setSlot(unsigned int slot);
	void setFrameIndex(unsigned int frameIndex);
	void setTransitionTime(unsigned int transitionTime);
	void setJointAngle(int* jointAngle);

private:
	unsigned int slot;
	unsigned int frameIndex;
	unsigned int transitionTime;
	int*         jointAngle;
	int 		 numberOfJoints;
};

#endif /* SRC_BEAN_MOTION_FRAME_H_ */
