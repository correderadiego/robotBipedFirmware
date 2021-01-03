/*
 * Frame.h
 *
 *  Created on: 5 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_MOTION_FRAME_H_
#define SRC_BEAN_MOTION_FRAME_H_

#include "Configuration.h"

class Frame {
public:
	Frame();
	Frame(
			unsigned int headerPosition,
			unsigned int frameIndex,
			unsigned int transitionTime
			);
	~Frame();
	struct FrameMemory{
			unsigned int headerPosition;
			unsigned int framePosition;
			unsigned int transitionTime;
			int         jointAngle[NUMBER_OF_JOINTS] = {};
			int 		numberOfJoints  = NUMBER_OF_JOINTS;
	};

	FrameMemory* getFrameMemory();
	unsigned int getHeaderPosition();
	unsigned int getFramePosition();
	unsigned int getTransitionTime();
	int* getJointAngle();

	void setHeaderPosition(unsigned int headerPosition);
	void setFramePosition(unsigned int frameIndex);
	void setTransitionTime(unsigned int transitionTime);

private:
	FrameMemory* frameMemory;
};

#endif /* SRC_BEAN_MOTION_FRAME_H_ */
