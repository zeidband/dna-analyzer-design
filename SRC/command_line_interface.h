//
// Created by a on 7/5/20.
//

#ifndef SRC_COMMAND_LINE_INTERFACE_H
#define SRC_COMMAND_LINE_INTERFACE_H


#include "parser.h"
#include "i_write.h"

class ICommand {
public:
    virtual bool run(Parser* input, IWrite* outputPrint) = 0;
};


#endif //SRC_COMMAND_LINE_INTERFACE_H
