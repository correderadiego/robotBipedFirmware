/*
 * Header.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_HEADER_H_
#define SRC_BEAN_MOTION_HEADER_H_

class Header {
public:

	Header();
	Header(
			char* motionName,
			unsigned int position,
			unsigned int motionFrameLenght,
			unsigned int loopBeginFrame,
			unsigned int loopEndFrame,
			unsigned int loopCount,
			unsigned int jumpSlot,
			bool extra,
			bool jump,
			bool loop
			);

	char* getMotionName();
	unsigned int getPosition();
	unsigned int getMotionFrameLength();
	unsigned int getLoopBeginFrame();
	unsigned int getLoopEndFrame();
	unsigned int getLoopCount();
	unsigned int getJumpSlot();

	bool useExtra();
	bool useJump();
	bool useLoop();

	void setMotionName(char* motionName);
	void setPosition(unsigned int);
	void setMotionFrameLength(unsigned int);
	void setLoopBeginFrame(unsigned int);
	void setLoopEndFrame(unsigned int);
	void setLoopCount(unsigned int);
	void setJumpSlot(unsigned int);

	void setExtra(bool extra);
	void setJump(bool jump);
	void setLoop(bool loop);

private:
	char* motionName;
	unsigned int position;
	unsigned int motionFrameLenght;
	unsigned int loopBeginFrame;
	unsigned int loopEndFrame;
	unsigned int loopCount;
	unsigned int jumpSlot;
	bool extra;
	bool jump;
	bool loop;
};

#endif /* SRC_BEAN_MOTION_HEADER_H_ */
