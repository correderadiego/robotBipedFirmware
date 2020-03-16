/*
 * Plen.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#include <Plen.h>

JointController*  Plen::joint_ctrl  = new JointController();
MotionController* Plen::motionController = new MotionController(*joint_ctrl);
Interpreter*      Plen::interpreter = new Interpreter(*motionController);
Plen*			  Plen::plen		= new Plen();

#if ENSOUL_PLEN2
	static AccelerationGyroSensor* sensor= new AccelerationGyroSensor();
	static Soul*                   soul  = new Soul(sensor, motionController);
#endif

void (Plen::*Plen::CONTROLLER_EVENT_HANDLER[])() = {
	&Plen::applyDiff,
	&Plen::apply,
	&Plen::homePosition,
	&Plen::playMotion,
	&Plen::stopMotion,
	&Plen::playMotion,
	&Plen::stopMotion
};

void (Plen::*Plen::INTERPRETER_EVENT_HANDLER[])() = {
	&Plen::popCode,
	&Plen::pushCode,
	&Plen::resetInterpreter
};

void (Plen::*Plen::SETTER_EVENT_HANDLER[])() = {
	&Plen::setHome,
	&Plen::setMotionHeader, // sanity check.
	&Plen::setJointSettings,
	&Plen::setMax,
	&Plen::setMotionFrame,
	&Plen::setMotionHeader,
	&Plen::setMin
};

void (Plen::*Plen::GETTER_EVENT_HANDLER[])() = {
	&Plen::getJointSettings,
	&Plen::getMotion,
	&Plen::getVersionInformation
};

void (Plen::**Plen::EVENT_HANDLER[])() = {
	Plen::CONTROLLER_EVENT_HANDLER,
	Plen::INTERPRETER_EVENT_HANDLER,
	Plen::SETTER_EVENT_HANDLER,
	Plen::GETTER_EVENT_HANDLER
};


Plen::Plen() {
	PLEN2::ExternalFs::init();
	Plen::joint_ctrl->init();
	System::setupWifiConnection();
}

/*
 *Controllers
 */

void Plen::plenController(){
	motionControl();
	systemSerial();
	tcpController();
}

void Plen::motionControl(){
	if (!Plen::motionController->playing()){
		return;
	}

	if (Plen::motionController->frameUpdatable()){
		Plen::motionController->updateFrame();
	}

	if (!Plen::motionController->updatingFinished()){
		return;
	}

	if (Plen::motionController->nextFrameLoadable()){
		Plen::motionController->loadNextFrame();
		return;
	}

	Plen::motionController->stop();
	if(Plen::interpreter->ready()){
		Plen::interpreter->popCode();
	}
}

void Plen::systemSerial(){
	if (!PLEN2::System::SystemSerial().available()){
		return;
	}

	Plen::plen->readByte(PLEN2::System::SystemSerial().read());

	if (Plen::plen->accept()){
		Plen::plen->transitState();
	}
}

void Plen::tcpController(){
	PLEN2::System::handleClient();

	if (!PLEN2::System::tcp_available()){
		return;
	}
	#if DEBUG_LESS
		uint8_t c = PLEN2::System::tcp_read();
		PLEN2::System::outputSerial().write(c);
		app.readByte(c);
	#else
		Plen::plen->readByte(PLEN2::System::tcp_read());
	#endif
	if (Plen::plen->accept()){
		Plen::plen->transitState();
	}
}

void Plen::applyDiff(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::applyDiff()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle_diff : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	this->joint_ctrl->setAngleDiff(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void Plen::apply(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::apply()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	this->joint_ctrl->setAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void Plen::homePosition(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::homePosition()"));
	#endif

	this->joint_ctrl->loadSettings();
}

void Plen::playMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::playMotion()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));
	#endif

	this->motionController->play(
		Utility::hexbytes2uint(m_buffer.data, 2)
	);
}

void Plen::stopMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::stopMotion()"));
	#endif

	this->motionController->willStop();
}

void Plen::popCode(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::popCode()"));
	#endif

	this->interpreter->popCode();
}

void Plen::pushCode(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::pushCode()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> loop_count : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data + 2, 2));
	#endif

	m_code_tmp.slot       = Utility::hexbytes2uint(m_buffer.data, 2);
	m_code_tmp.loop_count = Utility::hexbytes2uint(m_buffer.data + 2, 2) - 1;

	this->interpreter->pushCode(m_code_tmp);
}

void Plen::resetInterpreter(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::resetInterpreter()"));
	#endif

	this->interpreter->reset();
}

void Plen::setHome(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setHome()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	this->joint_ctrl->setHomeAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void Plen::setJointSettings(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setJointSettings()"));
	#endif

	this->joint_ctrl->resetSettings();
}

void Plen::setMax(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMax()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	this->joint_ctrl->setMaxAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void Plen::setMotionFrame(){
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

void Plen::setMotionHeader(){
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

void Plen::setMin(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::setMin()"));

		System::debugSerial().print(F(">>> joint_id : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));

		System::debugSerial().print(F(">>> angle : "));
		System::debugSerial().println(Utility::hexbytes2int(m_buffer.data + 2, 3));
	#endif

	joint_ctrl->setMinAngle(
		Utility::hexbytes2uint(m_buffer.data, 2),
		Utility::hexbytes2int(m_buffer.data + 2, 3)
	);
}

void Plen::getJointSettings(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getJointSettings()"));
	#endif

	joint_ctrl->dump();
}

void Plen::getMotion(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getMotion()"));

		System::debugSerial().print(F(">>> slot : "));
		System::debugSerial().println(Utility::hexbytes2uint(m_buffer.data, 2));
	#endif

	motionController->dump(
		Utility::hexbytes2uint(m_buffer.data, 2)
	);
}

void Plen::getVersionInformation(){
	#if DEBUG_LESS
		volatile Utility::Profiler p(F("Application::getVersionInformation()"));
	#endif

	System::dump();
}


void Plen::afterHook(){
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

