/*
 * ExternalFsController.cpp
 *
 *  Created on: 17 mar. 2020
 *      Author: Diego
 */

#include <hardware/controller/ExternalFileSystemController.h>

ExternalFileSystemController::ExternalFileSystemController() {}

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
	float percentaje = 0;

	*file = SPIFFS.open(filePath, FILE_MODE_WRITE);
	unsigned int sizeWrite = 0;
	for (i = 0, startAddress = 0; i < (unsigned int)(fileSize / bufferSize); i++, startAddress += bufferSize){
		FileSystemErrors filesystemErrors = write(startAddress, bufferSize, buf, &sizeWrite, file);
		percentaje = ((float)startAddress / (float)fileSize)*100;
		Logger::getInstance()->log(Logger::INFO, static_cast<float>(percentaje));
		Logger::getInstance()->logln(Logger::INFO, S("%"));

		if(filesystemErrors != NO_ERROR){
			Logger::getInstance()->log(Logger::ERROR, S(" *** Error creating file : "));
			Logger::getInstance()->logln(Logger::ERROR, filePath);
			return;
		}
	}
	file->close();
	Logger::getInstance()->log(Logger::INFO, S(" *** Created file : "));
	Logger::getInstance()->logln(Logger::INFO, filePath);
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

	if (!file->seek(startAddress, SeekSet)){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error finding file location *** "));
		return SEEK_ERROR;
	}
	*sizeWrite = file->write(data, size);
	if(*sizeWrite != size){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write size write error ***"));
		return WRITE_SIZE_ERROR;
	}
	file->flush();
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

	if (!file->seek(startAddress, SeekSet)){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error finding file location *** "));
		return SEEK_ERROR;
	}
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

	if (!file->seek(startAddress, SeekSet)){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error finding file location *** "));
		return SEEK_ERROR;
	}
	sizeWrite = file->write(data);

	if( sizeWrite != WRITE_BYTE_SIZE){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write byte size write error ***"));
		return WRITE_SIZE_ERROR;
	}
	file->flush();
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readSlot(
									unsigned int  slot,
									unsigned char data[],
									unsigned char readSize,
									File* file
								){
	if(*file == -1){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write byte file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	if(readSize > SLOT_SIZE_BYTES){
		return SLOT_SIZE_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_SLOT_SIZE_BYTES;

	if (!file->seek(dataAddress, SeekSet)){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error finding file location *** "));
		return SEEK_ERROR;
	}
	file->read(data, readSize);
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeSlot(
									unsigned int  slot,
									const unsigned char data[],
									unsigned char writeSize,
									File* file
								){
	if(*file == -1){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Write byte file doesn't exist *** "));
		return FILE_DOESNT_EXIST_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_SLOT_SIZE_BYTES;

	if(!file->seek(dataAddress, SeekSet)){
		Logger::getInstance()->logln(Logger::ERROR, S(" *** Error finding file location *** "));
        return SEEK_ERROR;
	}

	file->write(data, writeSize);
	file->flush();
	return NO_ERROR;
}
