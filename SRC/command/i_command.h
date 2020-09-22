//
// Created by a on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H


#include "../manager/parser.h"
#include "../writer/i_write.h"

class ICommand {
public:
    virtual ~ICommand() {}

    virtual bool run(IWrite* outputPrint) = 0;

    virtual void setArgs(Parser& args) = 0;

protected:
    bool isExistId(std::string &id);

    bool isExistName(std::string &name);
};


#endif //SRC_I_COMMAND_H
