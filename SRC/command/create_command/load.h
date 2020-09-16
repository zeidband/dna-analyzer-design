//
// Created by a on 7/7/20.
//

#ifndef SRC_LOAD_H
#define SRC_LOAD_H

#include "../i_command.h"
#include <map>


class Load : public ICommand {

public:
    bool run(Parser& input, IWrite* outputPrint);

    void isOk(Parser& args);

    typedef std::map<std::string, size_t> sequenceName;

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    static sequenceName _sequenceFilesAndCount;
};


#endif //SRC_LOAD_H
