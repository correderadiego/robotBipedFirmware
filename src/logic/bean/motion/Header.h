/*
 * Header.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_MOTION_HEADER_H_
#define SRC_BEAN_MOTION_HEADER_H_

class Header {
	#define NAME_LENGTH      			21
	#define FRAME_LENGTH_MIN  			 1
	#define FRAME_LENGTH_MAX 			20
	#define STOP_FLAG_DEFAULT_VALUE		0xFF
	#define LOOP_COUNT_INFINITY_VALUE 	255
	#define SLOT_BEGIN 					0
	#define SLOT_END  					90

public:
	Header();
	enum state{
		ENABLE 	= 1,
		DISABLE = 0
	};


private:
	unsigned char slot;
	char motionName[NAME_LENGTH];
	unsigned char motionFrameLenght;

	unsigned char useExtra;
	unsigned char useJump ;
	unsigned char useLoop ;

	unsigned char loopBegin;
	unsigned char loopEnd;

	unsigned char loopCount;
	unsigned char jumpSlot;
	unsigned char stop_flags[2];
};

#endif /* SRC_BEAN_MOTION_HEADER_H_ */
