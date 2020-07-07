//
// Created by a on 7/6/20.
//

#include <iostream>
#include "command_factory.h"
#include "new_command_class.h"


CommandFactory::~CommandFactory() {
    delete _command;
}


ICommand *CommandFactory::getCommand(Parser *command) {
    delete _command;

    if(command->_argsList[0] == "new")
        _command = new NewCommandClass(command);

    else
        throw std::invalid_argument("There is no such command");

    return _command;
}


