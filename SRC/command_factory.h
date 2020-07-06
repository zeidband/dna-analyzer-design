//
// Created by a on 7/6/20.
//

#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include "command_line_interface.h"

// need to check if to every command it will do new + delete?????????????????

class CommandFactory {
public:
    CommandFactory() : _command(NULL) {}

    ~CommandFactory();

    ICommand* getCommand(Parser*);

private:
    ICommand *_command;
};


#endif //SRC_COMMAND_FACTORY_H
