//
// Created by a on 7/6/20.
//

#include <iostream>
#include <cstring>
#include "command_factory.h"
#include "new_command_class.h"


CommandFactory::~CommandFactory() {
    delete _command;
}


ICommand *CommandFactory::getCommand(Parser *command) {
    if(strcmp(command->_argsList[0].c_str(), "new") == 0) {
        ICommand* temp = new NewCommandClass(command);
        delete _command;
        _command = temp;
    }

    else
        throw std::invalid_argument("There is no such command");

    return _command;
}


