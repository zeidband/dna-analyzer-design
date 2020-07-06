//
// Created by a on 7/6/20.
//

#include "command_factory.h"
#include "new_command_class.h"

CommandFactory::~CommandFactory() {
    if (_command) {
        delete _command;
    }
}

ICommand *CommandFactory::getCommand(Parser *) {
    if(!_command) {
        delete _command;
    }

    _command = new new_command_class;

    return _command;
}


