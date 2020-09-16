//
// Created by a on 7/8/20.
//

#ifndef SRC_DUP_H
#define SRC_DUP_H

#include "load.h"

class Dup : public ICommand {
public:
    void isOk(Parser& args);

    bool run(Parser& input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    static Load::sequenceName _sequenceFilesAndCount;
};


#endif //SRC_DUP_H
