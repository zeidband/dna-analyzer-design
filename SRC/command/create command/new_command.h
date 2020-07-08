//
// Created by a on 7/6/20.
//

#ifndef SRC_NEW_COMMAND_H
#define SRC_NEW_COMMAND_H

#include "../command_line_interface.h"

class New : public ICommand {
public:
    New() {}

    New(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    bool isDna(std::string &dna);
};


#endif //SRC_NEW_COMMAND_H
