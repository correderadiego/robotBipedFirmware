/*
 * ParserController.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <controller/ParserController.h>

ParserController::ParserController() {}

ParserController::ParseErrors ParserController::parse(Buffer* buffer, Command command){
	if (buffer->getPosition() < command.getCommandLength()){
		return INCOMPLETE_MESSAGE;
	}

	if(command.getCommandState() == Command::HEADER_INCOMING2){
		return parseHeader('x', command);
	}

	if(command.getCommandState() == Command::COMMAND_INCOMING2){
		//return parseControllerCommand("xx", command);
	}

	if(command.getCommandState() == Command::ARGUMENTS_INCOMING2){
		//return parseCommand("xx", ControllerCommand(command));
		return NO_ERROR;
	}

	return NO_ERROR;
}

ParserController::ParseErrors ParserController::parseHeader(char character, Command command){
	if(character == CONTROLLER_COMMAND_CHAR){
		command = *(new ControllerCommand());
		return NO_ERROR;
	}

	if(character == INTERPRETER_COMMAND_CHAR){
		command = *(new InterpreterCommand());
		return NO_ERROR;
	}

	if(character == SETTER_COMMAND_CHAR){
		command = *(new SetterCommand());
		return NO_ERROR;
	}

	if(character == GETTER_COMMAND_CHAR){
		command = *(new GetterCommand());
		return NO_ERROR;
	}

	command.setCommandType(Command::UNKNOWN_COMMAND_TYPE);
	return UNKNOWN_COMMAND;
}

ParserController::ParseErrors ParserController::parseCommand(char character, Command command){
	if(command.getCommandType() == Command::CONTROLLER_COMMAND){
		return parseControllerCommand(character,(ControllerCommand)command);
	}

	if(command.getCommandType() == Command::INTERPRETER_COMMAND){
		return parseInterpreterCommand(character,);
	}

	if(command.getCommandType() == Command::SETTER_COMMAND){
		return parseSetterCommand(character,);
	}

	if(command.getCommandType() == Command::GETTER_COMMAND){
		return parseGetterCommand(character,);
	}

	return UNKNOWN_COMMAND;
}

ParserController::ParseErrors ParserController::parseControllerCommand(
									char* characters, ControllerCommand command){
	if( strcmp(characters, APPY_NATIVE_CHAR) == 0){
		command.setSubCommandType(ControllerCommand::APPY_NATIVE_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, APPLY_DIFF_CHAR) == 0){
		command.setSubCommandType(ControllerCommand::APPLY_DIFF_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, PLAY_A_MOTION_CHAR) == 0){
		command.setSubCommandType(ControllerCommand::PLAY_A_MOTION);
		return NO_ERROR;
	}

	if( strcmp(characters, STOP_A_MOTION_CHAR) == 0){
		command.setSubCommandType(ControllerCommand::STOP_A_MOTION);
		return NO_ERROR;
	}

	if( strcmp(characters, APPLY_HOME_POSITION_CHAR) == 0){
		command.setSubCommandType(ControllerCommand::APPLY_HOME_POSITION);
		return NO_ERROR;
	}

	command.setSubCommandType(ControllerCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return UNKNOWN_COMMAND;
}

ParserController::ParseErrors ParserController::parseInterpreterCommand(
									char* characters, InterpreterCommand command){
	if( strcmp(characters, PUSH_FUNCTION_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::PUSH_FUNCTION_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, POP_FUNCTION_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::POP_FUNCTION_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, RESET_INTERPRETER_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::RESET_INTERPRETER);
		return NO_ERROR;
	}

	command.setSubCommandType(InterpreterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return UNKNOWN_COMMAND;
}

ParserController::ParseErrors ParserController::parseSetterCommand(
									char* characters, SetterCommand command){
	if( strcmp(characters, SET_MOTION_HEADER_CHAR) == 0){
		command.setSubCommandType(SetterCommand::SET_MOTION_HEADER);
		return NO_ERROR;
	}

	if( strcmp(characters, SET_MOTION_FRAME_CHAR) == 0){
		command.setSubCommandType(SetterCommand::SET_MOTION_FRAME);
		return NO_ERROR;
	}

	if( strcmp(characters, RESET_JOINT_SETTINGS_CHAR) == 0){
		command.setSubCommandType(SetterCommand::RESET_JOINT_SETTINGS);
		return NO_ERROR;
	}

	if( strcmp(characters, SET_HOME_VALUE_CHAR) == 0){
		command.setSubCommandType(SetterCommand::SET_HOME_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, SET_MAX_VALUE_CHAR) == 0){
		command.setSubCommandType(SetterCommand::SET_MAX_VALUE);
		return NO_ERROR;
	}

	if( strcmp(characters, SET_MIN_VALUE_CHAR) == 0){
		command.setSubCommandType(SetterCommand::SET_MIN_VALUE);
		return NO_ERROR;
	}

	command.setSubCommandType(SetterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return UNKNOWN_COMMAND;
}

ParserController::ParseErrors ParserController::parseGetterCommand(
									char* characters, GetterCommand command){
	if( strcmp(characters, DUMP_JOINT_SETTINGS_CHAR) == 0){
		command.setSubCommandType(GetterCommand::DUMP_JOINT_SETTINGS);
		return NO_ERROR;
	}

	if( strcmp(characters, DUMP_A_MOTION_CHAR) == 0){
		command.setSubCommandType(GetterCommand::DUMP_A_MOTION);
		return NO_ERROR;
	}

	if( strcmp(characters, DUMP_VERSION_INFORMATION_CHAR) == 0){
		command.setSubCommandType(GetterCommand::DUMP_VERSION_INFORMATION);
		return NO_ERROR;
	}

	command.setSubCommandType(GetterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return UNKNOWN_COMMAND;
}


