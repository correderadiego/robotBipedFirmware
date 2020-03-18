/*
	Copyright (c) 2015,
	- Kazuyuki TAKASE - https://github.com/junbowu
	- PLEN Project Company Inc. - https://plen.jp

	This software is released under the MIT License.
	(See also : http://opensource.org/licenses/mit-license.php)
*/

#include "JointController.h"

//Hardware definition
Adafruit_PWMServoDriver pwmServoDriver;
Servo GPIO12SERVO;
Servo GPIO14SERVO;

//Thread definition
Ticker updateServoThread;
Ticker updateEyesThread;
#define UPDATE_SERVO_EXECUTION 100 	//ms
#define UPDATE_EYES_EXECUTION 	1 	//s

//File configuration
extern File fileConfiguration;

volatile bool PLEN2::JointController::m_1cycle_finished = false;
int PLEN2::JointController::m_pwms[PLEN2::JointController::SUM];

namespace
{
	namespace Shared
	{
		using namespace PLEN2;

		PROGMEM const int m_SETTINGS_INITIAL[] =
		{
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  -40, // [01] Left : Shoulder Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  245, // [02] Left : Thigh Yaw
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  470, // [03] Left : Shoulder Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -100, // [04] Left : Elbow Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -205, // [05] Left : Thigh Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,   50, // [06] Left : Thigh Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  445, // [07] Left : Knee Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  245, // [08] Left : Foot Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  -75, // [09] Left : Foot Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2,
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2,
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2,
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,   15, // [10] Right : Shoulder Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  -70, // [11] Right : Thigh Yaw
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -390, // [12] Right : Shoulder Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  250, // [13] Right : Elbow Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,  195, // [14] Right : Thigh Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -105, // [15] Right : Thigh Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -510, // [16] Right : Knee Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, -305, // [17] Right : Foot Pitch
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2,   60, // [18] Right : Foot Roll
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2,
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2,
			JointController::ANGLE_MIN_2, JointController::ANGLE_MAX_2, JointController::ANGLE_NEUTRAL_2
		};

		const int ERROR_LVALUE = -32768;
	}
}


void PLEN2::JointController::configurePins(){
    GPIO12SERVO.attach(Pin::PWM_OUT_12());
    GPIO14SERVO.attach(Pin::PWM_OUT_14());
}


void PLEN2::JointController::loadJointInitialSettings(){
}

void PLEN2::JointController::init(){
	configurePins();
    loadSettings();
}

PLEN2::JointController::JointController(){}

void PLEN2::JointController::loadSettings(){
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::loadSettings()"));
	#endif

	unsigned char* filler = reinterpret_cast<unsigned char*>(m_SETTINGS);
	
	if (ExternalFs::readByte(INIT_FLAG_ADDRESS(), fileConfiguration) != INIT_FLAG_VALUE()){
		ExternalFs::writeByte(INIT_FLAG_ADDRESS(), INIT_FLAG_VALUE(), fileConfiguration);
        ExternalFs::write(SETTINGS_HEAD_ADDRESS(), sizeof(m_SETTINGS), filler, fileConfiguration);
		System::debugSerial().println(F("reset config\n"));
	}else{
		ExternalFs::read(SETTINGS_HEAD_ADDRESS(), sizeof(m_SETTINGS), filler, fileConfiguration);
		System::debugSerial().println(F("read config"));
	}

	for (char joint_id = 0; joint_id < SUM; joint_id++){
		setAngle(joint_id, m_SETTINGS[joint_id].HOME);
	}

	PLEN2::JointController::updateAngle(200);
    updateServoThread.attach_ms	(UPDATE_SERVO_EXECUTION, PLEN2::JointController::updateAngle,0);
    //updateEyesThread.attach		(UPDATE_EYES_EXECUTION , PLEN2::JointController::updateEyes);
}


void PLEN2::JointController::resetSettings()
{
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::resetSettings()"));
	#endif
	
    ExternalFs::writeByte(INIT_FLAG_ADDRESS(), INIT_FLAG_VALUE(), fileConfiguration);

	for (char joint_id = 0; joint_id < SUM; joint_id++)
	{
		m_SETTINGS[joint_id].MIN  = Shared::m_SETTINGS_INITIAL[joint_id * 3];
		m_SETTINGS[joint_id].MAX  = Shared::m_SETTINGS_INITIAL[joint_id * 3 + 1];
		m_SETTINGS[joint_id].HOME = Shared::m_SETTINGS_INITIAL[joint_id * 3 + 2];

		setAngle(joint_id, m_SETTINGS[joint_id].HOME);
	}
	
    ExternalFs::write(SETTINGS_HEAD_ADDRESS(), sizeof(m_SETTINGS), 
                    reinterpret_cast<const unsigned char*>(m_SETTINGS), fileConfiguration);
}


bool PLEN2::JointController::setMinAngle(unsigned char joint_id, int angle)
{
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::setMinAngle()"));
	#endif

	if (joint_id >= SUM)
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : joint_id = "));
			System::debugSerial().println(static_cast<int>(joint_id));
		#endif

		return false;
	}

	if (   (angle >= m_SETTINGS[joint_id].MAX)
		|| (angle <  ANGLE_MIN_2) )
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : angle = "));
			System::debugSerial().println(angle);
		#endif

		return false;
	}


	m_SETTINGS[joint_id].MIN = angle;

	unsigned char* filler = reinterpret_cast<unsigned char*>(&(m_SETTINGS[joint_id].MIN));
	int address_offset    = reinterpret_cast<int>(filler) - reinterpret_cast<int>(m_SETTINGS);

	#if DEBUG
		System::debugSerial().print(F(">>> address_offset : "));
		System::debugSerial().println(address_offset);
	#endif

	ExternalFs::write(SETTINGS_HEAD_ADDRESS() + address_offset, sizeof(m_SETTINGS[joint_id].MIN), filler, fileConfiguration);

	return true;
}


bool PLEN2::JointController::setMaxAngle(unsigned char joint_id, int angle)
{
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::setMaxAngle()"));
	#endif

	if (joint_id >= SUM)
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : joint_id = "));
			System::debugSerial().println(static_cast<int>(joint_id));
		#endif

		return false;
	}

	if (   (angle <= m_SETTINGS[joint_id].MIN)
		|| (angle >  ANGLE_MAX_2) )
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : angle = "));
			System::debugSerial().println(angle);
		#endif

		return false;
	}


	m_SETTINGS[joint_id].MAX = angle;

	unsigned char* filler = reinterpret_cast<unsigned char*>(&(m_SETTINGS[joint_id].MAX));
	int address_offset    = reinterpret_cast<int>(filler) - reinterpret_cast<int>(m_SETTINGS);

	#if DEBUG
		System::debugSerial().print(F(">>> address_offset : "));
		System::debugSerial().println(address_offset);
	#endif

	ExternalFs::write(SETTINGS_HEAD_ADDRESS() + address_offset, sizeof(m_SETTINGS[joint_id].MAX), filler, fileConfiguration);

	return true;
}


bool PLEN2::JointController::setHomeAngle(unsigned char joint_id, int angle)
{
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::setHomeAngle()"));
	#endif

	if (joint_id >= SUM)
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : joint_id = "));
			System::debugSerial().println(static_cast<int>(joint_id));
		#endif

		return false;
	}

	if (   (angle < m_SETTINGS[joint_id].MIN)
		|| (angle > m_SETTINGS[joint_id].MAX) )
	{
		#if DEBUG
			System::debugSerial().print(F(">>> bad argment! : angle = "));
			System::debugSerial().println(angle);
		#endif

		return false;
	}


	m_SETTINGS[joint_id].HOME = angle;

	unsigned char* filler = reinterpret_cast<unsigned char*>(&(m_SETTINGS[joint_id].HOME));
	int address_offset    = reinterpret_cast<int>(filler) - reinterpret_cast<int>(m_SETTINGS);

	#if DEBUG
		System::debugSerial().print(F(">>> address_offset : "));
		System::debugSerial().println(address_offset);
	#endif

	ExternalFs::write(SETTINGS_HEAD_ADDRESS() + address_offset, sizeof(m_SETTINGS[joint_id].HOME), filler, fileConfiguration);

	return true;
}

//设置角度
bool PLEN2::JointController::setAngle(unsigned char joint_id, int angle){
	#if DEBUG_HARD
		volatile Utility::Profiler p(F("JointController::setAngle()"));
	#endif

	if (joint_id >= SUM)
	{
		#if DEBUG_HARD
			System::debugSerial().print(F(">>> bad argment! : joint_id = "));
			System::debugSerial().println(static_cast<int>(joint_id));
		#endif

		return false;
	}

	angle = constrain(angle, m_SETTINGS[joint_id].MIN, m_SETTINGS[joint_id].MAX);
	if(joint_id  == 0 || joint_id == 12){
		#if CLOCK_WISE
			m_pwms[joint_id] = 90 + angle / 10;
		#else
			m_pwms[joint_id] = 90 - angle / 10;
		#endif
	}
	else
	{
		m_pwms[joint_id] = map(
			angle,
			PLEN2::JointController::ANGLE_MIN_2, PLEN2::JointController::ANGLE_MAX_2,

			#if CLOCK_WISE
				PLEN2::JointController::PWM_MIN(), PLEN2::JointController::PWM_MAX()
			#else
				PLEN2::JointController::PWM_MAX(), PLEN2::JointController::PWM_MIN()
			#endif
		);
	}
#if DEBUG_LESS
	System::debugSerial().print(F(": joint_id = "));
	System::debugSerial().print(static_cast<int>(joint_id));
	System::debugSerial().print(F(": angle = "));
	System::debugSerial().print(static_cast<int>(angle));
	System::debugSerial().print(F(": pwmServoDriver = "));
	System::debugSerial().print(static_cast<int>(m_pwms[joint_id]));
#endif
	return true;
}

//设置角度差
bool PLEN2::JointController::setAngleDiff(unsigned char joint_id, int angle_diff)
{
	#if DEBUG_HARD
		volatile Utility::Profiler p(F("JointController::setAngleDiff()"));
	#endif

	if (joint_id >= SUM)
	{
		#if DEBUG_HARD
			System::debugSerial().print(F(">>> bad argment! : joint_id = "));
			System::debugSerial().println(static_cast<int>(joint_id));
		#endif

		return false;
	}


	int angle = constrain(
		angle_diff + m_SETTINGS[joint_id].HOME,
		m_SETTINGS[joint_id].MIN, m_SETTINGS[joint_id].MAX
	);

	if(joint_id  == 0 || joint_id == 12)
	{
		#if CLOCK_WISE
			m_pwms[joint_id] = 90 + angle / 10;
		#else
			m_pwms[joint_id] = 90 - angle / 10;
		#endif
	}
	else
	{
		m_pwms[joint_id] = map(
			angle,
			PLEN2::JointController::ANGLE_MIN_2, PLEN2::JointController::ANGLE_MAX_2,

			#if CLOCK_WISE
				PLEN2::JointController::PWM_MIN(), PLEN2::JointController::PWM_MAX()
			#else
				PLEN2::JointController::PWM_MAX(), PLEN2::JointController::PWM_MIN()
			#endif
		);
	}

	return true;
}


void PLEN2::JointController::dump()
{
	#if DEBUG
		volatile Utility::Profiler p(F("JointController::dump()"));
	#endif
	System::outputSerial().println(F("["));

	for (char joint_id = 0; joint_id < SUM; joint_id++){
		System::outputSerial().println(F("\t{"));

		System::outputSerial().print(F("\t\t\"max\": "));
		System::outputSerial().print(m_SETTINGS[joint_id].MAX);
		System::outputSerial().println(F(","));

		System::outputSerial().print(F("\t\t\"min\": "));
		System::outputSerial().print(m_SETTINGS[joint_id].MIN);
		System::outputSerial().println(F(","));

		System::outputSerial().print(F("\t\t\"home\": "));
		System::outputSerial().println(m_SETTINGS[joint_id].HOME);
    //wifi_tcp_server.write(m_SETTINGS[joint_id].HOME);

		System::outputSerial().print(F("\t}"));

		if (joint_id != (SUM - 1))
		{
			System::outputSerial().println(F(","));
		}
		else
		{
			System::outputSerial().println();
		}
	}

	System::outputSerial().println(F("]"));
	System::outputSerial().println(F("\r\n"));
}


/*
	@brief Timer 1 overflow interruption vector

	The interruption vector runs at the moment TCNT1 overflowed.
	In the firmware, 16[MHz] clock source is prescaled by 64, and using 10bit mode,
	so interruption interval is (16,000,000 / (64 * 1,024))^-1 * 1,000 = 4.096[msec].

	The value is too smaller than servo's PWM acceptable interval,
	so the firmware can control 24 servos by outputting PWM once in 8 times
	and changing output line at each interruption timing.

	@attention
	Please add volatile prefix to all editable instance of the vector,
	for countermeasure of optimization.

	The MCU outputs PWM with double-buffering so joint selection should look ahead next joint.
	If fail to do the procedure, controlling plural servos is not to be you intended.
*/
/*
 * TODO: update angle
 */
const unsigned char servo_map[PLEN2::JointController::SUM] = {16, 7, 6, 5, 4, 3, 2, 1, 0, 18, 19, 20, 17, 8, 9, 10, 11, 12, 13, 14, 15, 21, 22, 23};
void PLEN2::JointController::updateAngle(int delayBetweenUpdates){
    for (int joint_id = 0; joint_id < SUM; joint_id++){
        if (servo_map[joint_id] < 16)
	    {
	        pwmServoDriver.setPWM(servo_map[joint_id], 0, m_pwms[joint_id]);
	    }
        else if (servo_map[joint_id] == 16)
        {
           GPIO12SERVO.write(m_pwms[joint_id]);
           
        }
        else if (servo_map[joint_id] == 17)
        {
            GPIO14SERVO.write(m_pwms[joint_id]);
        }
        delay(delayBetweenUpdates);
    }
	PLEN2::JointController::m_1cycle_finished = true;
}
