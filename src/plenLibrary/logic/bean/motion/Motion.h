	/*
 * Motion.h
 *
 *  Created on: 5 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_MOTION_MOTION_H_
#define SRC_BEAN_MOTION_MOTION_H_

#include <logic/bean/motion/Frame.h>
#include <logic/bean/motion/Header.h>

class Motion {
public:
	Motion(Header* header, Frame** frame);
	~Motion();

	void setHeader(Header* header);
	Header* getHeader();
	void setFrameVector(Frame** frameVector);
	Frame** getFrameVector();
	void setFrameExecutingPosition(unsigned int frameExecutingPosition);
	unsigned int getFrameExecutingPosition();
	void setLoopExecutingPosition(unsigned int loopExecutingPosition);
	unsigned int getLoopExecutingPosition();

private:
	unsigned int frameExecutingPosition;
	unsigned int loopExecutingPosition;
	Header* header;
	Frame** frameVector;
};

#endif /* SRC_BEAN_MOTION_MOTION_H_ */
