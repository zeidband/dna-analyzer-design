//
// Created by a on 7/6/20.
//

#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include "i_command.h"

// need to check if to every command it will do create command + delete?????????????????

class CommandFactory {
public:
    CommandFactory() : _command(NULL) {}

    ~CommandFactory();

    ICommand* getCommand(Parser&);

private:
    ICommand *_command;
};


#endif //SRC_COMMAND_FACTORY_H
