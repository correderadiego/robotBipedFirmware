/*
 * Motion.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/bean/motion/Motion.h>

Motion::Motion(Header* header, Frame* frame){
	this->header = header;
	this->frame  = frame;
}
