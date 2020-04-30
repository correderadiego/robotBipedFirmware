/*
 * ExternalFsController.h
 *
 *  Created on: 17 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_
#define SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_

#include <logic/bean/hardware/Joint.h>
#include <logic/bean/Plen.h>
#include "FS.h"

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define EEPROM_CHUNK_SIZE		32
#define SLOT_SIZE				30
#define SLOT_BEGIN				0
#define SLOT_END				0x200000L/EEPROM_CHUNK_SIZE

#define INIT_FLAG_ADDRESS     	0
#define	INIT_FLAG_VALUE  		2
#define SETTINGS_HEAD_ADDRESS 	1

#define END_OF_LINE 			'\n'

class ExternalFileSystemController {
public:
	enum FileSystemErrors{
	  NO_ERROR,
	  MOUNTING_FILESISTEM_ERROR,
	  UNKNOWN_FILE_FORMAT,
	  SEEK_ERROR,
	  SLOT_SIZE_ERROR,
	  SLOT_END_ERROR,
	  WRITE_SIZE_ERROR ,
	  FILE_DOESNT_EXIST_ERROR
	};

	ExternalFileSystemController();
	FileSystemErrors initExternalFileSystemController();
	bool isFileConfigurationInitiated(Plen* plen);
	void initFileConfiguration(Plen* plen);
	ExternalFileSystemController::FileSystemErrors readAccesPointNamePassword(
			File* fileConfiguration, String apName, String password);
	void writeMinAngle (Plen* plen, Joint* joint);
	void writeMaxAngle (File* fileConfiguration, Joint* joint);
	void writeHomeAngle(File* fileConfiguration, Joint* joint);

	void createAndResetFile(
					File* file,
					const char* filePath,
					int fileSize,
					unsigned char* buf,
					int bufferSize);
	void createFile(
					File* file,
					const char* filePath,
					int fileSize,
					unsigned char* buf,
					int bufferSize);
	FileSystemErrors read(
					unsigned int start_addr,
					unsigned int size,
					unsigned char data[],
					int* sizeRead,
					File* file);
	FileSystemErrors write(
					unsigned int start_addr,
					unsigned int size,
					const unsigned char data[],
					unsigned int* sizeWrite,
					File* file);
	FileSystemErrors readByte(
					unsigned int start_addr,
					unsigned char* data,
					File* file);
	FileSystemErrors writeByte(
					unsigned int start_addr,
					unsigned char data,
					unsigned int sizeWrite,
					File* file);
	FileSystemErrors readSlot(
					unsigned int  slot,
					unsigned char data[],
					unsigned char read_size,
					File* file);
	FileSystemErrors writeSlot(
					unsigned int  slot,
					const unsigned char data[],
					unsigned char writeSize,
					File* file);
};

#endif /* SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_ */
