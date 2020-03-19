/*
 * Plen.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#include "PlenController.h"

#if ENSOUL_PLEN2
	static AccelerationGyroSensor* sensor= new AccelerationGyroSensor();
	static Soul*                   soul  = new Soul(sensor, motionController);
#endif

void (PlenController::*PlenController::CONTROLLER_EVENT_HANDLER[])() = {
	&PlenController::applyDiff,
	&PlenController::apply,
	&PlenController::homePosition,
	&PlenController::playMotion,
	&PlenController::stopMotion,
	&PlenController::playMotion,
	&PlenController::stopMotion
};

void (PlenController::*PlenController::INTERPRETER_EVENT_HANDLER[])() = {
	&PlenController::popCode,
	&PlenController::pushCode,
	&PlenController::resetInterpreter
};

void (PlenController::*PlenController::SETTER_EVENT_HANDLER[])() = {
	&PlenController::setHome,
	&PlenController::setMotionHeader, // sanity check.
	&PlenController::setJointSettings,
	&PlenController::setMax,
	&PlenController::setMotionFrame,
	&PlenController::setMotionHeader,
	&PlenController::setMin
};

void (PlenController::*PlenController::GETTER_EVENT_HANDLER[])() = {
	&PlenController::getJointSettings,
	&PlenController::getMotion,
	&PlenController::getVersionInformation
};

void (PlenController::**PlenController::EVENT_HANDLER[])() = {
	PlenController::CONTROLLER_EVENT_HANDLER,
	PlenController::INTERPRETER_EVENT_HANDLER,
	PlenController::SETTER_EVENT_HANDLER,
	PlenController::GETTER_EVENT_HANDLER
};


PlenController::PlenController(
		JointController*  jointController,
		MotionController* motionController,
		Interpreter*      interpreter,
		EyeController*	  eyeController,
		ExternalFileSystemController* externalFileSystemController) {
		this->jointController = jointController;
		this->motionController= motionController;
		this->interpreter	  = interpreter;
		this->eyeController	  = eyeController;
		this->externalFileSystemController = externalFileSystemController;
}

void PlenController::initPlenController(Plen* plen){
	loadFileConfiguration(plen);
	jointController->init();
	System::setupWifiConnection();
}

void PlenController::loadFileConfiguration(Plen* plen){
	if(externalFileSystemController->isFileConfigurationInitiated(plen)){
		externalFileSystemController->loadFileConfiguration(plen);
		return;
	}
	externalFileSystemController->initFileConfiguration(plen);
}

/*
 *Controllers
 */

void PlenController::executeThreadTasks(Plen* plen){
	motionControl();
	systemSerial();
	tcpController();
	eyeController->executeThreadTasks(plen->getEyes());
}

void PlenController::motionControl(){
	if (!motionController->playing()){
		return;
	}

	if (motionController->frameUpdatable()){
		motionController->updateFrame();
	}

	if (!motionController->updatingFinished()){
		return;
	}

	if (motionController->nextFrameLoadable()){
		motionController->loadNextFrame();
		return;
	}

	motionController->stop();
	if(interpreter->ready()){
		interpreter->popCode();
	}
}

void PlenController::systemSerial(){
	if (!PLEN2::System::SystemSerial().available()){
		return;
	}

	readByte(PLEN2::System::SystemSerial().read());

	if (accept()){
		transitState();
	}
}

void PlenController::tcpController(){
	PLEN2::System::handleClient();

	if (!PLEN2::System::tcp_available()){
		return;
	}
	#if DEBUG_LESS
		uint8_t c = PLEN2::System::tcp_read();
		PLEN2::System::outputSerial().write(c);
		app.readByte(c);
	#else
		readByte(PLEN2::System::tcp_read());
	#endif
	if (accept()){
		transitState();
	}
}

void PlenController::applyDiff(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::applyDiff()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle_diff : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	jointController->setAngleDiff(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void PlenController::apply(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::apply()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	jointController->setAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void PlenController::homePosition(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::homePosition()"));
	#endif

	jointController->loadSettings();
}

void PlenController::playMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::playMotion()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));
	#endif

	motionController->play(
		Utility::hexbytes2uint(m_buffer.data, 2)
	);
}

void PlenController::stopMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::stopMotion()"));
	#endif

	motionController->willStop();
}

void PlenController::popCode(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::popCode()"));
	#endif

	interpreter->popCode();
}

void PlenController::pushCode(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::pushCode()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> loop_count : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 2, 2));
	#endif

	m_code_tmp.slot       = Utility::hexbytes2uint(m_buffer.data, 2);
	m_code_tmp.loop_count = Utility::hexbytes2uint(m_buffer.data + 2, 2) - 1;

	interpreter->pushCode(m_code_tmp);
}

void PlenController::resetInterpreter(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::resetInterpreter()"));
	#endif

	interpreter->reset();
}

void PlenController::setHome(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setHome()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	jointController->setHomeAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void PlenController::setJointSettings(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setJointSettings()"));
	#endif

	jointController->resetSettings();
}

void PlenController::setMax(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMax()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

		jointController->setMaxAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void PlenController::setMotionFrame(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMotionFrame()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> frame_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 2, 2));

		System::debugSerial().print(F(">>> transition_time_ms : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 4, 4));

		for (int device_id = 0; device_id < JointController::SUM; device_id++){
			System::debugSerial().print(F(">>> output["));
			System::debugSerial().print(device_id);
			System::debugSerial().print(F("] : "));
			System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 8 + device_id * 4, 4));
		}
	#endif

	m_frame_tmp.transition_time_ms = Utility::hexbytes2uint(m_buffer.data + 4, 4);

	for (char device_id = 0; device_id < JointController::SUM; device_id++){
		m_frame_tmp.joint_angle[device_id] = Utility::hexbytes2int(m_buffer.data + 8 + device_id * 4, 4);
	}

	if (m_installing){
		if (m_frame_tmp.index < m_header_tmp.frame_length){
			m_frame_tmp.set(m_header_tmp.slot);
			m_frame_tmp.index++;
		}

		if (m_frame_tmp.index == m_header_tmp.frame_length){
			m_installing = false;
		}else{
			readByte('>');
			accept();
			transitState();

			readByte('m');
			readByte('f');
			accept();
			transitState();

			readByte('0'); // dummy
			readByte('0'); // dummy
			readByte('0'); // dummy
			readByte('0'); // dummy
		}
	}else
	{
		m_frame_tmp.index = Utility::hexbytes2uint(m_buffer.data + 2, 2);
		m_frame_tmp.set(Utility::hexbytes2uint(m_buffer.data, 2));
	}
}

void PlenController::setMotionHeader(){
	strncpy(m_header_tmp.name, m_buffer.data + 2, 20);
	m_header_tmp.name[20] = '\0';
	m_buffer.data[2]      = '\0';

	if (   !(m_parser[ARGUMENTS_INCOMING]->parse(m_buffer.data))
		|| !(m_parser[ARGUMENTS_INCOMING]->parse(m_buffer.data + 22)) )
	{
		return;
	}

	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMotionHeader()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> name : "));
		System::debugSerial().println(m_header_tmp.name);

		System::debugSerial().print(F(">>> func : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 22, 2));

		System::debugSerial().print(F(">>> arg0 : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 24, 2));

		System::debugSerial().print(F(">>> arg1 : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 26, 2));

		System::debugSerial().print(F(">>> frame_length : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 28, 2));
	#endif

	m_header_tmp.slot         = Utility::hexbytes2uint(m_buffer.data, 2);
	m_header_tmp.frame_length = Utility::hexbytes2uint(m_buffer.data + 28, 2);

	switch (Utility::hexbytes2uint(m_buffer.data + 22, 2))
	{
		case 0:
		{
			m_header_tmp.use_loop = 0;
			m_header_tmp.use_jump = 0;

			break;
		}

		case 1:
		{
			m_header_tmp.use_loop   = 1;
			m_header_tmp.use_jump   = 0;
			m_header_tmp.loop_begin = Utility::hexbytes2uint(m_buffer.data + 24, 2);
			m_header_tmp.loop_end   = Utility::hexbytes2uint(m_buffer.data + 26, 2);

			break;
		}

		case 2:
		{
			m_header_tmp.use_loop  = 0;
			m_header_tmp.use_jump  = 1;
			m_header_tmp.jump_slot = Utility::hexbytes2uint(m_buffer.data + 24, 2);

			break;
		}
	}

	m_header_tmp.set();

	if (m_installing == true)
	{
		readByte('>');
		accept();
		transitState();

		readByte('m');
		readByte('f');
		accept();
		transitState();

		readByte('0'); // dummy
		readByte('0'); // dummy
		readByte('0'); // dummy
		readByte('0'); // dummy

		m_frame_tmp.index = 0;
	}
}

void PlenController::setMin(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMin()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	jointController->setMinAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void PlenController::getJointSettings(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getJointSettings()"));
	#endif

	jointController->dump();
}

void PlenController::getMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getMotion()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));
	#endif

	motionController->dump(
		Utility::hexbytes2uint(m_buffer.data, 2)
	);
}

void PlenController::getVersionInformation(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getVersionInformation()"));
	#endif

	System::dump();
}


void PlenController::afterHook(){
	#if DEBUG
		volatile Utility::Profiler p(F("Application::afterFook()"));
	#endif

	if (m_state == HEADER_INCOMING){
		unsigned char header_id = m_parser[HEADER_INCOMING ]->index();
		unsigned char cmd_id    = m_parser[COMMAND_INCOMING]->index();

		(this->*EVENT_HANDLER[header_id][cmd_id])();

		#if ENSOUL_PLEN2
			soul.userActionInputed();
		#endif
	}
}

