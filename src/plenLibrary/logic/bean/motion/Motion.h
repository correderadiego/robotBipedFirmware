/*
 * Motion.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_MOTION_H_
#define SRC_BEAN_MOTION_MOTION_H_

#include <logic/bean/motion/Frame.h>
#include <logic/bean/motion/Header.h>

class Motion {
public:
	Motion(Header* header, Frame* frame);
	Header* getHeader();
	Frame* getFrame();
	void setFrame(Frame* frame);
private:
	Header* header;
	Frame frame[FRAME_NUMBER_MAX]={};
};

#endif /* SRC_BEAN_MOTION_MOTION_H_ */
