/*
 * Joint.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "Joint.h"

Joint::Joint(PwmPin* pwmPin,int angleHome,  RotationMode rotationMode) {
	this->pwmPin		= pwmPin;
	this->angleMin 	 	= ANGLE_MIN;
	this->angleMax 	 	= ANGLE_MAX;
	this->angleHome 	= angleHome;
	this->angle			= angleHome;
	this->rotationMode  = rotationMode;
}

void Joint::setAngleHome(int angleHome){
	this->angleHome = angleHome;
}

void Joint::setAngleMin(int angleMin){
	this->angleMin = angleMin;
}

void Joint::setAngleMax(int angleMax){
	this->angleMax = angleMax;
}

void Joint::setAngle(int angle){
	int temporalAngle = constrain(angle, angleMin, angleMax);
	if(this->rotationMode == Joint::counterClockWise){
		temporalAngle = 90 - angle / 10;
	}
	this->angle = temporalAngle;
}

int Joint::getAngleHome(){
	return this->angleHome;
}

int Joint::getAngleMin(){
	return this->angleMin;
}

int Joint::getAngleMax(){
	return this->angleMax;
}

int Joint::getAngle(){
	return this->angle;
}

PwmPin* Joint::getPwmPin(){
	return this->pwmPin;
}

Joint::RotationMode Joint::getRotationMode(){
	return this->rotationMode;
}

void Joint::dump(){
	Logger::getInstance()->log(Logger::INFO, F("["));
	Logger::getInstance()->log(Logger::INFO, F("\t{"));

	Logger::getInstance()->log(Logger::INFO, F("\t\t\"max\": "));
	Logger::getInstance()->log(Logger::INFO, (String)angleMax);
	Logger::getInstance()->log(Logger::INFO,F(","));


	Logger::getInstance()->log(Logger::INFO, F("\t\t\"min\": "));
	Logger::getInstance()->log(Logger::INFO, (String)angleMin);
	Logger::getInstance()->log(Logger::INFO, F(","));

	Logger::getInstance()->log(Logger::INFO, F("\t\t\"home\": "));
	Logger::getInstance()->log(Logger::INFO, (String)angleHome);
	Logger::getInstance()->log(Logger::INFO, F("]"));
	Logger::getInstance()->log(Logger::INFO, F("\r\n"));
}
