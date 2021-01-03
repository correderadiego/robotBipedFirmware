/*
 * Joint.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/hardware/Joint.h>
#include "ArduinoIncludes.h"

Joint::Joint(PwmPinInterface* pwmPinInterface, int angleHome, RotationMode rotationMode, bool enabled) {
	this->jointMemory 		     = {ANGLE_MIN, ANGLE_MAX, angleHome};
	this->defaultHome			 = angleHome;
	this->pwmPinInterface		 = pwmPinInterface;
	this->angle					 = angleHome;
	this->rotationMode  		 = rotationMode;
	this->enabled				 = enabled;
}

Joint::JointMemory* Joint::getJointMemory(){
	return &this->jointMemory;
}

int Joint::getDefaultAngleHome(){
	return this->defaultHome;
}

void Joint::setAngleHome(int angleHome){
	this->jointMemory.angleHome = angleHome;
}

void Joint::setAngleMin(int angleMin){
	this->jointMemory.angleMin = angleMin;
}

void Joint::setAngleMax(int angleMax){
	this->jointMemory.angleMax = angleMax;
}

void Joint::setAngle(int angle){
	this->angle = constrain(angle, this->jointMemory.angleMin, this->jointMemory.angleMax);
}

int Joint::getAngleHome(){
	return this->jointMemory.angleHome;
}

int Joint::getAngleMin(){
	return this->jointMemory.angleMin;
}

int Joint::getAngleMax(){
	return this->jointMemory.angleMax;
}

int Joint::getAngle(){
	return this->angle;
}

PwmPinInterface* Joint::getPwmPin(){
	return this->pwmPinInterface;
}

Joint::RotationMode Joint::getRotationMode(){
	return this->rotationMode;
}

bool Joint::isEnabled(){
	return this->enabled;
}

void Joint::setEnabled(bool enabled){
	this->enabled = enabled;
}
