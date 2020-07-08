//
// Created by a on 7/6/20.
//

#include <iostream>
#include <cstring>
#include "command_factory.h"
#include "create command/new_command.h"
#include "create command/dup_command.h"
#include "create command/quit_command.h"


CommandFactory::~CommandFactory() {
    delete _command;
}


ICommand *CommandFactory::getCommand(Parser &command) {
    //check to under conditions
    //keep in list

    if(!strcmp(command._args[0].c_str(), "new")) {
        ICommand* temp = new New(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "load")) {
        ICommand* temp = new Load(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "dup")) {
        ICommand* temp = new Dup(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "quit")) {
        ICommand* temp = new Quit;
        delete _command;
        _command = temp;
    }

    else
        throw std::invalid_argument("There is no such command");

    return _command;
}


