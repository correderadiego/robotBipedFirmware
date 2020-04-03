/*
 * Joint.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <bean/Joint.h>

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
	this->angle = angle;
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
	Serial.println(F("["));
	Serial.println(F("\t{"));

	Serial.print(F("\t\t\"max\": "));
	Serial.print(angleMax);
	Serial.println(F(","));

	Serial.print(F("\t\t\"min\": "));
	Serial.print(angleMin);
	Serial.println(F(","));

	Serial.print(F("\t\t\"home\": "));
	Serial.println(angleHome);
	Serial.println(F("]"));
	Serial.println(F("\r\n"));
}
