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

    virtual void isOk(Parser& args) = 0;

    virtual bool run(Parser& input, IWrite* outputPrint) = 0;

protected:

    bool isDna(std::string &dna);

    bool isExistId(std::string &id);

    bool isExistName(std::string &name);
};


#endif //SRC_I_COMMAND_H
