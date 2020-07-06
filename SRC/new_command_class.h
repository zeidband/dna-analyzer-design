//
// Created by a on 7/6/20.
//

#ifndef SRC_NEW_COMMAND_CLASS_H
#define SRC_NEW_COMMAND_CLASS_H

#include "i_create_commands.h"

class new_command_class : public ICreateCommands {
public:
    bool run(Parser* input, IWrite* outputPrint);
};


#endif //SRC_NEW_COMMAND_CLASS_H
