/*
	Copyright (c) 2015,
	- Kazuyuki TAKASE - https://github.com/junbowu
	- PLEN Project Company Inc. - https://plen.jp

	This software is released under the MIT License.
	(See also : http://opensource.org/licenses/mit-license.php)
*/
#include "Arduino.h"
#include <Wire.h>

#include "ExternalFs.h"
#include "System.h"
#include "Profiler.h"

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

File fp_motion;
File fp_config;
File fp_syscfg;

void PLEN2::ExternalFs::init(){
	File fp;
	unsigned char buf[BUF_SIZE] = {1};

#if DEBUG
    System::debugSerial().println("SPIFFS opened: " + result);
#endif

    if (!SPIFFS.exists(MOTION_FILE) ||
        !SPIFFS.exists(CONFIG_FILE) ||
        !SPIFFS.exists(SYSCFG_FILE)
		){

    	createFile(fp, MOTION_FILE_SIZE, buf, BUF_SIZE);
    	createFile(fp, CONFIG_FILE_SIZE, buf, BUF_SIZE );
    	createFile(fp, SYSCFG_FILE_SIZE, buf, BUF_SIZE);

        System::outputSerial().println("fs formated\n");
    }
    fp_motion = SPIFFS.open(MOTION_FILE, FILE_MODE_READ);
    fp_config = SPIFFS.open(CONFIG_FILE, FILE_MODE_READ);
//  fp_syscfg = SPIFFS.open(SYSCFG_FILE, FILE_MODE_READ_APPEND);
}

void PLEN2::ExternalFs::createFile(
								File fp,
								int fileSize,
								unsigned char* buf,
								int bufferSize){
	unsigned int i;
	unsigned int start_addr;

	fp = SPIFFS.open(MOTION_FILE, FILE_MODE_WRITE);
	for (i = 0, start_addr = 0; i < fileSize / bufferSize; i++, start_addr += bufferSize){
		write(start_addr, bufferSize, buf, fp);
	}
	fp.close();
}

char PLEN2::ExternalFs::read(
							unsigned int start_addr,
							unsigned int size,
							unsigned char data[],
							File fp
							){
    if (!fp){
    	return -1;
    }

	fp.seek(start_addr, SeekSet);
	return fp.read(data, size);
}

char PLEN2::ExternalFs::write(
								unsigned int start_addr,
								unsigned int size,
								const unsigned char data[],
								File fp
							){
	if (!fp){
		return -1;
	}

	unsigned int write_size;
	fp.seek(start_addr, SeekSet);
	write_size = fp.write(data, size);
	fp.flush();
	return write_size == size;
}

unsigned char PLEN2::ExternalFs::readByte(
											unsigned int start_addr,
											File fp
										){
    unsigned char data;
    if (!fp){
    	return -1;
    }

	fp.seek(start_addr, SeekSet);
	data = (unsigned char )fp.read();
	return data;
}

char PLEN2::ExternalFs::writeByte(
									unsigned int start_addr,
									unsigned char data,
									File fp
									){

	#define WRITE_BYTE_SIZE 1

    if (!fp){
    	return -1;
    }
    unsigned int write_size;
	fp.seek(start_addr, SeekSet);
	write_size = fp.write(data);
	fp.flush();
	return write_size == WRITE_BYTE_SIZE;
}

char PLEN2::ExternalFs::readSlot(
									unsigned int  slot,
									unsigned char data[],
									unsigned char read_size,
									File fp
								){
	#if DEBUG
		volatile Utility::Profiler p(F("ExternalFs::readSlot()"));
	#endif
	if (   (slot >= SLOT_END())
		|| (read_size > SLOT_SIZE()
		|| !fp)
	)
	{
		#if DEBUG_LESS
			System::debugSerial().print(F(">>> bad argument! : slot = "));
			System::debugSerial().print(slot);
			System::debugSerial().print(F(", or read_size = "));
			System::debugSerial().print(read_size);
			System::debugSerial().print(F(", or fp = "));
			System::debugSerial().println(fp);
		#endif

		return -1;
	}

	unsigned int data_address = slot * EEPROM_CHUNK_SIZE();

	#if DEBUG
		System::debugSerial().print(F(">>> data_address = "));
		System::debugSerial().print(slot);
		System::debugSerial().print(F(" : "));
		System::debugSerial().println(data_address, HEX);
	#endif
	if (!fp.seek(data_address, SeekSet))
	{
        System::debugSerial().println(F(">>>readSlot Seek Error"));
	}
	read_size = fp.read(data, read_size);
	return read_size;
}

char PLEN2::ExternalFs::writeSlot(
									unsigned int  slot,
									const unsigned char data[],
									unsigned char write_size,
									File fp
								){

	#if DEBUG
		volatile Utility::Profiler p(F("ExternalFs::writeSlot()"));
	#endif
	
	if ( (slot >= SLOT_END()) || (write_size > SLOT_SIZE() || !fp)){
		#if DEBUG_LESS
			System::debugSerial().print(F(">>> bad argument! : slot = "));
			System::debugSerial().print(slot);
			System::debugSerial().print(F(", or write_size = "));
			System::debugSerial().print(write_size);
     		System::debugSerial().print(F(", or fp = "));
			System::debugSerial().println(fp);
		#endif

		return -1;
	}

	unsigned int data_address = slot * EEPROM_CHUNK_SIZE();

	#if DEBUG
		System::debugSerial().print(F(">>> data_address : "));
		System::debugSerial().print(slot);
		System::debugSerial().print(F(" : "));
		System::debugSerial().println(data_address, HEX);
	#endif

	if(!fp.seek(data_address, SeekSet)){
        System::debugSerial().println(F(">>>writeSlot: Seek Error"));
	}
	write_size = fp.write(data, write_size);
	fp.flush();
	return 0;
}
