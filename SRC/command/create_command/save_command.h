//
// Created by a on 7/10/20.
//

#ifndef SRC_SAVE_COMMAND_H
#define SRC_SAVE_COMMAND_H

#include "../i_command.h"

class Save : public ICommand {
public:
    void isOk(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);
};


#endif //SRC_SAVE_COMMAND_H
