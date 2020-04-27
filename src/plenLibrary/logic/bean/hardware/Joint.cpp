/*
 * Joint.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/hardware/Joint.h>

Joint::Joint(PwmPinInterface* pwmPinInterface, int angleHome,  RotationMode rotationMode) {
	this->pwmPinInterface		= pwmPinInterface;
	this->angleMin 	 			= ANGLE_MIN;
	this->angleMax 	 			= ANGLE_MAX;
	this->angleHome 			= angleHome;
	this->angle					= angleHome;
	this->rotationMode  		= rotationMode;
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
	//int temporalAngle = constrain(angle, angleMin, angleMax);
	int temporalAngle = angle;
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

PwmPinInterface* Joint::getPwmPin(){
	return this->pwmPinInterface;
}

Joint::RotationMode Joint::getRotationMode(){
	return this->rotationMode;
}

void Joint::dump(){
	Logger::getInstance()->log(Logger::INFO, S("\t{"));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"max\": "));
	Logger::getInstance()->log(Logger::INFO, this->angleMax);
	Logger::getInstance()->log(Logger::INFO, S(","));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"min\": "));
	Logger::getInstance()->log(Logger::INFO, this->angleMin);
	Logger::getInstance()->log(Logger::INFO, S(","));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"home\": "));
	Logger::getInstance()->log(Logger::INFO, this->angleHome);
	Logger::getInstance()->log(Logger::INFO, S("\t}"));
}
