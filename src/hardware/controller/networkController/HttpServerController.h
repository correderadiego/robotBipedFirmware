/*
 * httpServerController.h
 *
 *  Created on: 21 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_HTTPSERVERCONTROLLER_H_
#define SRC_HTTPSERVERCONTROLLER_H_

#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <FS.h>
#include <ESP8266mDNS.h>
#include "hardware/bean/Network.h"
#include "utils/Logger.h"
#include "Configuration.h"
#include "ArduinoIncludes.h"

class HttpServerController {
public:
	HttpServerController();
	void configureHttpServer(Network* network);
	void initHttpServer();
	void executeThreadTasks();
private:
	static ESP8266WebServer* 		httpServer;
	static ESP8266HTTPUpdateServer* httpUpdater;

	static void handleRoot();
	static void handleFileList();
	static bool handleFileRead(String path);
	static void handleFileCreate();
	static void handleFileDelete();
	static String getContentType(String filename);
	static void handleFileUpload();
};

#endif /* SRC_HTTPSERVERCONTROLLER_H_ */
