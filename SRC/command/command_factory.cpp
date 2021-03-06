//
// Created by a on 7/6/20.
//

#include <iostream>
#include <cstring>
#include "../exceptions/wrong_command.h"
#include "command_factory.h"
#include "create_command/new.h"
#include "create_command/load.h"
//#include "create_command/dup.h"
#include "create_command/quit.h"
//#include "create_command/save.h"
//#include "create_command/slice.h"


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
    // TODO: check to under conditions

    if ( command._args.size() == 0 ) {
        throw WrongCommand();
    }

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

//    else if(!strcmp(command._args[0].c_str(), "dup")) {
//        if(!isCommandExist(command._args[0])) {
//            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Dup));
//        }
//    }
//
//    else if(!strcmp(command._args[0].c_str(), "slice")) {
//        if(!isCommandExist(command._args[0])) {
//            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Slice));
//        }
//    }
//
//    else if(!strcmp(command._args[0].c_str(), "save")) {
//        if(!isCommandExist(command._args[0])) {
//            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Save));
//        }
//    }

    else if(!strcmp(command._args[0].c_str(), "quit")) {
        if(!isCommandExist(command._args[0])) {
            _commands.insert(std::pair<std::string, ICommand*>(command._args[0], new Quit));
        }
    }

    else {
        throw WrongCommand();
    }

    _commands[command._args[0]]->setArgs(command);

    return _commands[command._args[0]];
}

bool CommandFactory::isCommandExist(std::string &command) {
    return _commands.find(command.c_str()) != _commands.end();
}

