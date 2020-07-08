//
// Created by a on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H


#include "../manager/parser.h"
#include "../write/i_write.h"

class ICommand {
public:
    virtual ~ICommand() {}

    virtual bool run(Parser* input, IWrite* outputPrint) = 0;
};


#endif //SRC_I_COMMAND_H
