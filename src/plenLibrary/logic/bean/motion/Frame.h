/*
 * Frame.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_FRAME_H_
#define SRC_BEAN_MOTION_FRAME_H_

class Frame {

#define UPDATE_SERVO_INTERVAL_MS 	32
#define FRAME_BEGIN 				 0
#define FRAME_END 					20
#define NUMBER_OF_JOINTS 24
public:
	Frame();
private:
	unsigned char frameIndex;
	unsigned int  transitionTimems;
	int           jointAngle[NUMBER_OF_JOINTS];
	unsigned char deviceValue[8];
};

#endif /* SRC_BEAN_MOTION_FRAME_H_ */
