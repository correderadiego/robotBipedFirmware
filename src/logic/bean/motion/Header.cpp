/*
 * Header.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Header.h>

Header::Header() {
		this->slot              		= 0;
		this->motionName[0]             = '\0';
		this->motionName[NAME_LENGTH]   = '\0';
		motionFrameLenght      			= FRAME_LENGTH_MIN;
		useExtra          				= DISABLE;
		useJump           				= DISABLE;
		useLoop           				= DISABLE;
		loopBegin         				= DISABLE;
		loopEnd           				= DISABLE;
		loopCount         				= LOOP_COUNT_INFINITY_VALUE;
		stop_flags[0]     				= STOP_FLAG_DEFAULT_VALUE;
		stop_flags[1]     				= STOP_FLAG_DEFAULT_VALUE;
		stop_flags[2]     				= STOP_FLAG_DEFAULT_VALUE;
}
