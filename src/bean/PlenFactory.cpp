/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "PlenFactory.h"

Plen* PlenFactory::getPlen() {
	/**
	 * Joint
	 */
	Joint* joint[] = {
						new Joint(new EmbeddedPwmPin(1),-40, Joint::counterClockWise), // [01] Left : Shoulder Pitch
						new Joint(new EmbeddedPwmPin(2),245), // [02] Left : Thigh Yaw
						new Joint(new EmbeddedPwmPin(3),470), // [03] Left : Shoulder Roll
						new Joint(new EmbeddedPwmPin(4),-100),// [04] Left : Elbow Roll
						new Joint(new EmbeddedPwmPin(5),-205),// [05] Left : Thigh Roll
						new Joint(new EmbeddedPwmPin(6),50), 	// [06] Left : Thigh Pitch
						new Joint(new EmbeddedPwmPin(7),445),	// [07] Left : Knee Pitch
						new Joint(new EmbeddedPwmPin(8),245),	// [08] Left : Foot Pitch
						new Joint(new EmbeddedPwmPin(9),-75), // [09] Left : Foot Roll
						new Joint(),
						new Joint(),
						new Joint(),
						new Joint(new EmbeddedPwmPin(10),  15, Joint::counterClockWise), 	// [10] Right : Shoulder Pitch
						new Joint(new EmbeddedPwmPin(11), -70),	// [11] Right : Thigh Yaw
						new Joint(new PCA9685PwmPin(12),  -390),// [12] Right : Shoulder Roll
						new Joint(new PCA9685PwmPin(13),   250),	// [13] Right : Elbow Roll
						new Joint(new EmbeddedPwmPin(14),  195),	// [14] Right : Thigh Roll
						new Joint(new EmbeddedPwmPin(15), -105),// [15] Right : Thigh Pitch
						new Joint(new EmbeddedPwmPin(16), -510),// [16] Right : Knee Pitch
						new Joint(new EmbeddedPwmPin(17), -305),// [17] Right : Foot Pitch
						new Joint(new EmbeddedPwmPin(18),   60),	// [18] Right : Foot Roll
						new Joint(),
						new Joint(),
						new Joint()
	};

	/**
	 * Eyes
	 */
	GPIOPin* gpioPinLed = new GPIOPin(PIN_LED, OUTPUT);
	Led* led 			= new Led(gpioPinLed);
	Eyes* eyes 			= new Eyes(led);

	//TODO review pointers
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
