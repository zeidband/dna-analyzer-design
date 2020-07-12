//
// Created by a on 7/6/20.
//

#include <iostream>
#include <cstring>
#include "command_factory.h"
#include "create command/new_command.h"
#include "create command/dup_command.h"
#include "create command/quit_command.h"
#include "create command/save_command.h"


CommandFactory::~CommandFactory() {
    std::map<std::string, ICommand*>::iterator iter, curr;

    for (iter = _commands.begin(); iter != _commands.end();) {
        curr = iter;
        ++iter;
        delete curr->second;
        _commands.erase(curr);
    }
}


ICommand *CommandFactory::getCommand(Parser &command) {
    //check to under conditions
    //keep in list

    if(!strcmp(command._args[0].c_str(), "new")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new New));
        }
    }

    else if(!strcmp(command._args[0].c_str(), "load")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Load));
        }
    }

    else if(!strcmp(command._args[0].c_str(), "dup")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Dup));
        }
    }

    else if(!strcmp(command._args[0].c_str(), "save")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Save));
        }
    }

    else if(!strcmp(command._args[0].c_str(), "quit")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Quit));
        }
    }

    else
        throw std::invalid_argument("There is no such command");

    _commands[command._args[0]]->isOk(command);
    return _commands[command._args[0]];
}

bool CommandFactory::isCommandExist(std::string &command) {
    return _commands.find(command.c_str()) != _commands.end();
}

