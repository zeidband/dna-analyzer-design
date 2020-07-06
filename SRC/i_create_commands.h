//
// Created by a on 7/6/20.
//

#ifndef SRC_I_CREATE_COMMANDS_H
#define SRC_I_CREATE_COMMANDS_H

#include "command_line_interface.h"

class ICreateCommands : public ICommand {
public:
    virtual bool run(Parser* input, IWrite* outputPrint) = 0;
};


#endif //SRC_I_CREATE_COMMANDS_H
