//
// Created by a on 7/6/20.
//

#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include "i_command.h"
#include <map>
// need to check if to every command it will do create_command + delete?????????????????

class CommandFactory {
public:
    ~CommandFactory();

    ICommand* getCommand(Parser&);

private:
    std::map<std::string, ICommand*> _commands;

    bool isCommandExist(std::string &command);
};


#endif //SRC_COMMAND_FACTORY_H
