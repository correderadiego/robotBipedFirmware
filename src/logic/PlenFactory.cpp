/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "PlenFactory.h"

Plen* PlenFactory::getPlen() {
	joint[0] =	new Joint(new PCA9685PwmPin(PIN_LEFT_SHOULDER_PITCH),-40, Joint::counterClockWise);
	joint[1] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_YAW),245);
	joint[2] =  new Joint(new PCA9685PwmPin(PIN_LEFT_SHOULDER_ROLL),470);
	joint[3] =	new Joint(new PCA9685PwmPin(PIN_LEFT_ELBOW_ROLL),-100);
	joint[4] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_ROLL),-205);
	joint[5] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_PITCH),50);
	joint[6] =	new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH),445);
	joint[7] =	new Joint(new PCA9685PwmPin(PIN_LEFT_FOOT_PITCH),245);
	joint[8] =	new Joint(new PCA9685PwmPin(PIN_LEFT_FOOT_ROLL),-75);
	joint[9] =	new Joint();
	joint[10] =	new Joint();
	joint[11] =	new Joint();
	joint[12] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_SHOULDER_PITCH),  15, Joint::counterClockWise);
	joint[13] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_YAW), -70);
	joint[14] =	new Joint(new EmbeddedPwmPin(PIN_RIGHT_SHOULDER_ROLl),  -390);
	joint[15] =	new Joint(new EmbeddedPwmPin(PIN_RIGHT_ELBOW_ROLL), 250);
	joint[16] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_ROLL),  195);
	joint[17] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_PITCH), -105);
	joint[18] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_KNEE_PITCH), -510);
	joint[19] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_FOOT_PITCH), -305);
	joint[20] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_FOOT_ROLL),   60);
	joint[21] =	new Joint();
	joint[22] =	new Joint();
	joint[23] =	new Joint();

	GPIOPin* gpioPinLed = new GPIOPin(PIN_LED, OUTPUT);
	Led* led 			= new Led(gpioPinLed);
	Eyes* eyes 			= new Eyes(led);

	File* fileMotion 		= new File();
	File* fileConfiguration = new File();
	File* fileSystemConfiguration = new File();
	this->openFiles(*fileMotion, *fileConfiguration, *fileSystemConfiguration);

	Wifi* wifi = createWifi(fileSystemConfiguration);

	return new Plen(joint, NUMBER_OF_JOINTS, wifi, eyes, fileMotion, fileConfiguration, fileSystemConfiguration);
}

void PlenFactory::openFiles(File fileMotion, File fileConfiguration, File fileSystemConfiguration){
	File file;
	unsigned char buf[BUF_SIZE] = {1};
	ExternalFileSystemController* externalFsController = new ExternalFileSystemController();
    if (!SPIFFS.exists(MOTION_FILE) || !SPIFFS.exists(CONFIG_FILE)){
    	externalFsController->createFile(
    			file, MOTION_FILE, MOTION_FILE_SIZE, buf, BUF_SIZE);
    	externalFsController->createFile(
    			file, CONFIG_FILE, CONFIG_FILE_SIZE, buf, BUF_SIZE );
    }
    fileMotion = SPIFFS.open(MOTION_FILE, FILE_MODE_READ);
    fileConfiguration = SPIFFS.open(CONFIG_FILE, FILE_MODE_READ);
    fileSystemConfiguration = SPIFFS.open(SYSTEM_FILE, FILE_MODE_READ);
}

Wifi* PlenFactory::createWifi(File* fileSystemConfiguration){
	if( !(fileSystemConfiguration&& fileSystemConfiguration->available())){
			return createDefaultWifi();
	}

	ExternalFileSystemController* externalFsController = new ExternalFileSystemController();
	String apName= "";
	String password = "";
	ExternalFileSystemController::FileSystemErrors fileSystemError =
			externalFsController->readAccesPointNamePassword(
					fileSystemConfiguration, apName, password);
	if(fileSystemError == ExternalFileSystemController::NO_ERROR){
		return new Wifi(
						apName,
						password,
						Wifi::ACCESS_POINT_MODE,
						new ESP8266WebServer(DEFAULT_HTTP_PORT),
						new ESP8266HTTPUpdateServer(),
						new WiFiServer(DEFAULT_WIFI_SOCKET_PORT)
						);
	}
	return createDefaultWifi();
}

Wifi* PlenFactory::createDefaultWifi(){
	String defaulAccessPointName = "ViVi-" + String(ESP.getChipId(),HEX);
	const char *defaultPassword = "12345678xyz";

	return new Wifi(
					defaulAccessPointName,
					defaultPassword,
					Wifi::WIFI_CONNECTION_MODE,
					new ESP8266WebServer(DEFAULT_HTTP_PORT),
					new ESP8266HTTPUpdateServer(),
					new WiFiServer(DEFAULT_WIFI_SOCKET_PORT));
}
