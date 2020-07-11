//
// Created by a on 7/10/20.
//

#ifndef SRC_SAVE_COMMAND_H
#define SRC_SAVE_COMMAND_H

#include "../i_command.h"

class Save : public ICommand {
public:
    Save(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    bool isDna(std::string &dna);

    bool isId(std::string &basicString);

    bool isName(std::string &basicString);
};


#endif //SRC_SAVE_COMMAND_H
