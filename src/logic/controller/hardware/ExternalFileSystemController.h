/*
 * ExternalFsController.h
 *
 *  Created on: 17 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_
#define SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_

#include "logic/bean/Plen.h"
#include "FS.h"

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define MOTION_FILE  "/motion.bin"
#define MOTION_FILE_SIZE 0x200000L

#define CONFIG_FILE  "/joint_cfg.bin"
#define CONFIG_FILE_SIZE 0x1000L

#define SYSTEM_FILE  "/sys_cfg.bin"
#define SYSTEM_FILE_SIZE 0x1000L

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
	  UNKNOWN_FILE_FORMAT,
	  SEEK_ERROR,
	  SLOT_SIZE_ERROR,
	  SLOT_END_ERROR,
	  WRITE_SIZE_ERROR  = -2,
	  FILE_DOESNT_EXIST_ERROR = -1,
	  NO_ERROR = 0
	};

	ExternalFileSystemController();
	bool isFileConfigurationInitiated(Plen* plen);
	void initFileConfiguration(Plen* plen);
	void loadFileConfiguration(Plen* plen);
	ExternalFileSystemController::FileSystemErrors readAccesPointNamePassword(
			File* fileConfiguration, String apName, String password);
	void writeMinAngle (File* fileConfiguration, Joint* joint);
	void writeMaxAngle (File* fileConfiguration, Joint* joint);
	void writeHomeAngle(File* fileConfiguration, Joint* joint);

	void createFile(
					File file,
					const char* filePath,
					int fileSize,
					unsigned char* buf,
					int bufferSize);
	FileSystemErrors read(
					unsigned int start_addr,
					unsigned int size,
					unsigned char data[],
					unsigned int sizeRead,
					File file);
	FileSystemErrors write(
					unsigned int start_addr,
					unsigned int size,
					const unsigned char data[],
					unsigned int sizeWrite,
					File file);
	FileSystemErrors readByte(
					unsigned int start_addr,
					unsigned char data,
					File file);
	FileSystemErrors writeByte(
					unsigned int start_addr,
					unsigned char data,
					unsigned int sizeWrite,
					File file);
	FileSystemErrors readSlot(
					unsigned int  slot,
					unsigned char data[],
					unsigned char read_size,
					File file);
	FileSystemErrors writeSlot(
					unsigned int  slot,
					const unsigned char data[],
					unsigned char writeSize,
					File file);
};

#endif /* SRC_CONTROLLER_EXTERNALFILESYSTEMCONTROLLER_H_ */
