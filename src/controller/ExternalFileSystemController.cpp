/*
 * ExternalFsController.cpp
 *
 *  Created on: 17 mar. 2020
 *      Author: ziash
 */

#include <controller/ExternalFileSystemController.h>

ExternalFileSystemController::ExternalFileSystemController() {}

void ExternalFileSystemController::createFile(
								File file,
								const char* filePath,
								int fileSize,
								unsigned char* buf,
								int bufferSize){
	unsigned int i;
	unsigned int startAddress;

	file = SPIFFS.open(filePath, FILE_MODE_WRITE);
	unsigned int sizeWrite = 0;
	for (i = 0, startAddress = 0; i < (unsigned int)(fileSize / bufferSize); i++, startAddress += bufferSize){
		write(startAddress, bufferSize, buf, sizeWrite, file);
	}
	file.close();
}

bool ExternalFileSystemController::isFileConfigurationInitiated(Plen* plen){
	unsigned char data = 0;
	this->readByte(INIT_FLAG_ADDRESS, data, *plen->getFileConfiguration());
	if ( data == INIT_FLAG_VALUE){
		return true;
	}
	return false;
}

void ExternalFileSystemController::initFileConfiguration(Plen* plen){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(plen->getJointVector());
	writeByte(INIT_FLAG_ADDRESS, (unsigned char)INIT_FLAG_VALUE, sizeWrite, *plen->getFileConfiguration());
	write(SETTINGS_HEAD_ADDRESS, sizeof(plen->getJointVector()), filler, sizeWrite, *plen->getFileConfiguration());
}

void ExternalFileSystemController::loadFileConfiguration(Plen* plen){
	unsigned char* filler = reinterpret_cast<unsigned char*>(plen->getJointVector());
	ExternalFs::read(SETTINGS_HEAD_ADDRESS, sizeof(plen->getJointVector()), filler, *plen->getFileConfiguration());
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::read(
								unsigned int startAddress,
								unsigned int size,
								unsigned char data[],
								unsigned int sizeRead,
								File file
							){

	if(!file){
		return FILE_DOESNT_EXIST_ERROR;
	}

	file.seek(startAddress, SeekSet);
	sizeRead = file.read(data, size);
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::write(
								unsigned int startAddress,
								unsigned int size,
								const unsigned char data[],
								unsigned int sizeWrite,
								File file
							){

	if(!file){
		return FILE_DOESNT_EXIST_ERROR;
	}

	file.seek(startAddress, SeekSet);
	sizeWrite = file.write(data, size);
	file.flush();
	if(sizeWrite != size){
		return WRITE_SIZE_ERROR;
	}

	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readByte(
											unsigned int startAddress,
											unsigned char data,
											File file
										){
	if (!file){
		return FILE_DOESNT_EXIST_ERROR;
	}

	file.seek(startAddress, SeekSet);
	data = (unsigned char) file.read();
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeByte(
											unsigned int startAddress,
											unsigned char data,
											unsigned int sizeWrite,
											File file
										){

	#define WRITE_BYTE_SIZE 1

	file.seek(startAddress, SeekSet);
	sizeWrite = file.write(data);
	file.flush();

	if( sizeWrite != WRITE_BYTE_SIZE){
		return WRITE_SIZE_ERROR;
	}
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readSlot(
									unsigned int  slot,
									unsigned char data[],
									unsigned char readSize,
									File file
								){
	if(file == -1){
		return FILE_DOESNT_EXIST_ERROR;
	}

	if ((slot >= SLOT_END)){
		 return SLOT_END_ERROR;
	}

	if(readSize > SLOT_SIZE){
		return SLOT_SIZE_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_CHUNK_SIZE;

	if (!file.seek(dataAddress, SeekSet)){
		return SEEK_ERROR;
	}
	readSize = file.read(data, readSize);
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeSlot(
									unsigned int  slot,
									const unsigned char data[],
									unsigned char writeSize,
									File file
								){

	if(file == -1){
		return FILE_DOESNT_EXIST_ERROR;
	}

	if ((slot >= SLOT_END)){
		 return SLOT_END_ERROR;
	}

	if(writeSize > SLOT_SIZE){
		return SLOT_SIZE_ERROR;
	}

	unsigned int dataAddress = slot * EEPROM_CHUNK_SIZE;

	if(!file.seek(dataAddress, SeekSet)){
        return SEEK_ERROR;
	}
	writeSize = file.write(data, writeSize);
	file.flush();
	return NO_ERROR;
}
