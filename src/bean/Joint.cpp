/*
 * Joint.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <bean/Joint.h>

Joint::Joint(int homePosition) {
	angleMin 	 		= ANGLE_MIN;
	angleMax 	 		= ANGLE_MAX;
	this->homePosition 	= homePosition;
}

void Joint::setHomePosition(int homePosition){
	this->homePosition = homePosition;
}
