/*
 * Motion.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Motion.h>

Motion::Motion(Header* header, Frame* frame){
	this->header = header;
	this->frame  = frame;
}

Header* Motion::getHeader(){
	return header;
}
Frame* Motion::getFrame(){
	return frame;
}
