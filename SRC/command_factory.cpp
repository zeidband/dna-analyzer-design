//
// Created by a on 7/6/20.
//

#include <iostream>
#include "command_factory.h"
#include "new_command_class.h"

CommandFactory::~CommandFactory() {
    if(_command) {
        delete _command;
    }
}

ICommand *CommandFactory::getCommand(Parser *command) {
    if(!_command) {
        delete _command;
    }

    if(command->_argsList[0] == "new")
        _command = new new_command_class(command);

    else
        throw std::invalid_argument("There is no such command");

    return _command;
}


