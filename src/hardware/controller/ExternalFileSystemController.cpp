/*
 * ExternalFsController.cpp
 *
 *  Created on: 17 mar. 2020
 *      Author: ziash
 */

#include <hardware/controller/ExternalFileSystemController.h>

ExternalFileSystemController::ExternalFileSystemController() {
	//this->initExternalFileSystemController();
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::initExternalFileSystemController(){
	if (!SPIFFS.begin()) {
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error mounting SPIFFS ***"));
		return MOUNTING_FILESISTEM_ERROR;
	}
	Logger::getInstance()->logln(Logger::DEBUG, S(" *** SPIFFS mounted ***"));
	return NO_ERROR;
}

void ExternalFileSystemController::createAndResetFile(
								File* file,
								const char* filePath,
								int fileSize,
								unsigned char* buf,
								int bufferSize){
	unsigned int i;
	unsigned int startAddress;

	*file = SPIFFS.open(filePath, FILE_MODE_WRITE);
	unsigned int sizeWrite = 0;
	for (i = 0, startAddress = 0; i < (unsigned int)(fileSize / bufferSize); i++, startAddress += bufferSize){
		write(startAddress, bufferSize, buf, &sizeWrite, file);
	}
	file->close();
	Logger::getInstance()->log(Logger::DEBUG, S(" *** Created file : "));
	Logger::getInstance()->logln(Logger::DEBUG, filePath);
}

void ExternalFileSystemController::createFile(
								File* file,
								const char* filePath,
								int fileSize,
								unsigned char* buf,
								int bufferSize){

	*file = SPIFFS.open(filePath, FILE_MODE_WRITE);
	file->close();
	Logger::getInstance()->log(Logger::DEBUG, S(" *** Created file : "));
	Logger::getInstance()->logln(Logger::DEBUG, filePath);
}

void ExternalFileSystemController::writeMinAngle(Plen* plen, Joint* joint){
//	unsigned char* filler 	= reinterpret_cast<unsigned char*>(&(joint->getAngleMin()));
//	int address_offset    	= reinterpret_cast<int>(filler) - reinterpret_cast<int>(plen->getJointVector());
//	write(SETTINGS_HEAD_ADDRESS + address_offset, sizeof(joint->getAngleMin()), filler, &sizeWrite, plen->getFileConfiguration());
}

void ExternalFileSystemController::writeMaxAngle(File* fileConfiguration, Joint* joint){
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint->getAngleMin());
//	int address_offset    = reinterpret_cast<int>(filler) - reinterpret_cast<int>(m_SETTINGS);
//	ExternalFs::write(SETTINGS_HEAD_ADDRESS() + address_offset, sizeof(m_SETTINGS[joint_id].MAX), filler, fileConfiguration);
}

void ExternalFileSystemController::writeHomeAngle(File* fileConfiguration, Joint* joint){
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint->getAngleMin());
//	int address_offset    = reinterpret_cast<int>(filler) - reinterpret_cast<int>(m_SETTINGS);
//	ExternalFs::write(SETTINGS_HEAD_ADDRESS() + address_offset, sizeof(m_SETTINGS[joint_id].HOME), filler, fileConfiguration);
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readAccesPointNamePassword(
	File* fileConfiguration, String apName, String password){
	fileConfiguration->seek(0, SeekSet);
	apName 		= fileConfiguration->readStringUntil(END_OF_LINE);
	password 	= fileConfiguration->readStringUntil(END_OF_LINE);
	if(apName.length() <= 1){
		return UNKNOWN_FILE_FORMAT;
	}
	return NO_ERROR;
}

bool ExternalFileSystemController::isFileInitiated(Plen* plen, File* file){
	unsigned char data = 0;

	this->readByte(INIT_FLAG_ADDRESS, &data, file);
	if ( data == (unsigned char)INIT_FLAG_VALUE){
		return true;
	}
	return false;
}

void ExternalFileSystemController::initFile(File* file){
	unsigned int sizeWrite = 0;
	writeByte(INIT_FLAG_ADDRESS, (unsigned char)INIT_FLAG_VALUE, sizeWrite, file);
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::read(
								unsigned int startAddress,
								unsigned int size,
								unsigned char data[],
								int* sizeRead,
								File* file
							){

	if(!file){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Read file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	file->seek(startAddress, SeekSet);
	*sizeRead = file->read(data, size);
	if(*sizeRead != size){
		Logger::getInstance()->logln(Logger::ERROR, S("Read size read error"));
		return WRITE_SIZE_ERROR;
	}
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::write(
								unsigned int startAddress,
								unsigned int size,
								const unsigned char data[],
								unsigned int* sizeWrite,
								File* file
							){

	if(!file){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	file->seek(startAddress, SeekSet);
	*sizeWrite = file->write(data, size);
	file->flush();
	if(*sizeWrite != size){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write size write error ***"));
		Logger::getInstance()->log(Logger::ERROR, S(" *** Size to write  : "));
		Logger::getInstance()->log(Logger::ERROR, size);
		Logger::getInstance()->log(Logger::ERROR, S(" *** Size wrote  : "));
		Logger::getInstance()->log(Logger::ERROR, *sizeWrite);
		return WRITE_SIZE_ERROR;
	}

	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readByte(
											unsigned int startAddress,
											unsigned char* data,
											File* file
										){
	if (!file){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Read byte file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	file->seek(startAddress, SeekSet);
	*data = (unsigned char) file->read();
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeByte(
											unsigned int startAddress,
											unsigned char data,
											unsigned int sizeWrite,
											File* file
										){

	#define WRITE_BYTE_SIZE 1

	if (!file){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write byte file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	file->seek(startAddress, SeekSet);
	sizeWrite = file->write(data);
	file->flush();

	if( sizeWrite != WRITE_BYTE_SIZE){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write byte size write error ***"));
		return WRITE_SIZE_ERROR;
	}
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readSlot(
									unsigned int  slot,
									unsigned char data[],
									unsigned char readSize,
									File* file
								){
	if(*file == -1){
		return FILE_DOESNT_EXIST_ERROR;
	}

	if ((slot >= SLOT_END)){
		 return SLOT_END_ERROR;
	}

	if(readSize > SLOT_SIZE){
		return SLOT_SIZE_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_CHUNK_SIZE;

	if (!file->seek(dataAddress, SeekSet)){
		return SEEK_ERROR;
	}
	readSize = file->read(data, readSize);
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeSlot(
									unsigned int  slot,
									const unsigned char data[],
									unsigned char writeSize,
									File* file
								){

	if(*file == -1){
		return FILE_DOESNT_EXIST_ERROR;
	}

	if ((slot >= SLOT_END)){
		 return SLOT_END_ERROR;
	}

	if(writeSize > SLOT_SIZE){
		return SLOT_SIZE_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_CHUNK_SIZE;

	if(!file->seek(dataAddress, SeekSet)){
        return SEEK_ERROR;
	}
	writeSize = file->write(data, writeSize);
	file->flush();
	return NO_ERROR;
}
