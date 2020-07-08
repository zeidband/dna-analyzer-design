//
// Created by a on 7/8/20.
//

#ifndef SRC_DUP_COMMAND_H
#define SRC_DUP_COMMAND_H

#include "load_command.h"

class Dup : public ICommand {
public:
    Dup(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    static Load::sequenceName _sequenceFilesAndCount;
};


#endif //SRC_DUP_COMMAND_H
