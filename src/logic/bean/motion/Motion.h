/*
 * Motion.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_MOTION_H_
#define SRC_BEAN_MOTION_MOTION_H_

#include "logic/bean/motion/Header.h"
#include "logic/bean/motion/Frame.h"

class Motion {
public:
	Motion(Header* header, Frame* frame);

private:
	Header* header;
	Frame* frame;
};

#endif /* SRC_BEAN_MOTION_MOTION_H_ */
