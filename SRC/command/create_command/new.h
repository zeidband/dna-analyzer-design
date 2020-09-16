//
// Created by a on 7/6/20.
//

#ifndef SRC_NEW_H
#define SRC_NEW_H

#include "../i_command.h"

class New : public ICommand {
public:
    void isOk(Parser& args);

    bool run(Parser& input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);
};


#endif //SRC_NEW_H
