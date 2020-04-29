/*
 * httpServerController.cpp
 *
 *  Created on: 21 mar. 2020
 *      Author: ziash
 */

#include <hardware/controller/networkController/HttpServerController.h>

ESP8266WebServer* 		 HttpServerController::httpServer  = NULL;
ESP8266HTTPUpdateServer* HttpServerController::httpUpdater = NULL;

HttpServerController::HttpServerController() {}

void HttpServerController::executeThreadTasks(){
	httpServer->handleClient();
}

void HttpServerController::handleRoot() {
	httpServer->send(200, "text/plain", "hello from esp8266 - 2!");
}

void HttpServerController::initHttpServer(){
	httpServer->begin();
}

void HttpServerController::configureHttpServer(Network* network){
	HttpServerController::httpServer 	= network->getHttpServer();
	HttpServerController::httpUpdater 	= network->getHttpUpdater();

	httpServer->on("/", handleRoot);
	//list directory
	httpServer->on("/list", HTTP_GET, HttpServerController::handleFileList);
	//load editor
	httpServer->on("/edit", HTTP_GET, [](){
		if(!handleFileRead("/edit.htm")) httpServer->send(404, "text/plain", "FileNotFound");
	});
	//create file
	httpServer->on("/edit", HTTP_PUT, HttpServerController::handleFileCreate);
	//delete file
	httpServer->on("/edit", HTTP_DELETE, handleFileDelete);
	//first callback is called after the request has ended with all parsed arguments
	//second callback handles file uploads at that location
	httpServer->on("/edit", HTTP_POST, [](){ httpServer->send(200, "text/plain", ""); }, handleFileUpload);
	//called when the url is not defined here
	//use it to load content from SPIFFS
	httpServer->onNotFound([](){
		if(!handleFileRead(httpServer->uri())){
		  httpServer->send(404, "text/plain", "FileNotFound");
		}
	});

	//get heap status, analog input value and all GPIO statuses in one json call
	httpServer->on("/all", HTTP_GET, [](){
	String json = "{";
	json += "\"heap\":"+String(ESP.getFreeHeap());
	json += ", \"analog\":"+String(analogRead(A0));
	json += ", \"gpio\":"+String((uint32_t)(((GPI | GPO) & 0xFFFF) | ((GP16I & 0x01) << 16)));
	json += "}";
	httpServer->send(200, "text/json", json);
	json = String();
	});
	httpUpdater->setup(httpServer);

	Logger::getInstance()->log(Logger::INFO, S(" +++ HTTP server started on port : "));
	Logger::getInstance()->logln(Logger::INFO, ((String)DEFAULT_HTTP_PORT).c_str());
}

void HttpServerController::handleFileList() {
	  if(!httpServer->hasArg("dir")) {httpServer->send(500, "text/plain", "BAD ARGS"); return;}

	  String path = httpServer->arg("dir");
	  Serial.println("handleFileList: " + path);
	  Dir dir = SPIFFS.openDir(path);
	  path = String();

	  String output = "[";
	  while(dir.next()){
		File entry = dir.openFile("r");
		if (output != "["){ output += ','; }
		bool isDir = false;
		output += "{\"type\":\"";
		output += (isDir)?"dir":"file";
		output += "\",\"name\":\"";
		output += String(entry.name()).substring(1);
		output += "\"}";
		entry.close();
	  }

	  output += "]";
	  httpServer->send(200, "text/json", output);
}

void HttpServerController::handleFileCreate(){
  if(httpServer->args() == 0)
    return httpServer->send(500, "text/plain", "BAD ARGS");
  String path = httpServer->arg(0);
  Serial.println("handleFileCreate: " + path);
  if(path == "/")
    return httpServer->send(500, "text/plain", "BAD PATH");
  if(SPIFFS.exists(path))
    return httpServer->send(500, "text/plain", "FILE EXISTS");
  File file = SPIFFS.open(path, "w");
  if(file)
    file.close();
  else
    return httpServer->send(500, "text/plain", "CREATE FAILED");
  httpServer->send(200, "text/plain", "");
  path = String();
}

void HttpServerController::handleFileDelete(){
  if(httpServer->args() == 0) return httpServer->send(500, "text/plain", "BAD ARGS");
  String path = httpServer->arg(0);
  Serial.println("handleFileDelete: " + path);
  if(path == "/")
    return httpServer->send(500, "text/plain", "BAD PATH");
  if(!SPIFFS.exists(path))
    return httpServer->send(404, "text/plain", "FileNotFound");
  SPIFFS.remove(path);
  httpServer->send(200, "text/plain", "");
  path = String();
}

bool HttpServerController::handleFileRead(String path){
    Serial.println("handleFileRead: " + path);
    if(path.endsWith("/")) path += "index.htm";
    String contentType = getContentType(path);
    String pathWithGz = path + ".gz";
    if(SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)){
		if(SPIFFS.exists(pathWithGz)) path += ".gz";
		File file = SPIFFS.open(path, "r");
		httpServer->streamFile(file, contentType);
		file.close();
		return true;
    }
    return false;
}

void HttpServerController::handleFileUpload(){
	File fsUploadFile;

	if(httpServer->uri() != "/edit") return;
	HTTPUpload& upload = httpServer->upload();
	if(upload.status != UPLOAD_FILE_START){
		return;
	}

	String filename = upload.filename;
	if(!filename.startsWith("/")){
		filename = "/"+filename;
	}
	Serial.print("handleFileUpload Name: "); Serial.println(filename);
	fsUploadFile = SPIFFS.open(filename, "w");
	filename = String();
	if(upload.status == UPLOAD_FILE_WRITE){
		Serial.print("handleFileUpload Data: "); Serial.println(upload.currentSize);
		if(fsUploadFile){fsUploadFile.write(upload.buf, upload.currentSize);}
		return;
	}
	if(upload.status == UPLOAD_FILE_END){
		if(fsUploadFile){fsUploadFile.close();}
		Serial.print("handleFileUpload Size: "); Serial.println(upload.totalSize);
		return;
	}
}

String HttpServerController::getContentType(
											String filename
											){
    if(httpServer->hasArg("download")) return "application/octet-stream";
    if(filename.endsWith(".htm")) return "text/html";
    if(filename.endsWith(".html")) return "text/html";
    if(filename.endsWith(".css")) return "text/css";
    if(filename.endsWith(".js")) return "application/javascript";
    if(filename.endsWith(".png")) return "image/png";
    if(filename.endsWith(".gif")) return "image/gif";
    if(filename.endsWith(".jpg")) return "image/jpeg";
    if(filename.endsWith(".ico")) return "image/x-icon";
    if(filename.endsWith(".xml")) return "text/xml";
    if(filename.endsWith(".pdf")) return "application/x-pdf";
    if(filename.endsWith(".zip")) return "application/x-zip";
    if(filename.endsWith(".gz")) return "application/x-gzip";
    return "text/plain";
}
