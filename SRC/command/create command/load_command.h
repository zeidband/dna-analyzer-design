//
// Created by a on 7/7/20.
//

#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H

#include "../i_command.h"
#include <map>


class Load : public ICommand {

public:
    Load(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

    typedef std::map<std::string, size_t> sequenceName;

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    bool isDna(std::string &dna);

    static sequenceName _sequenceFilesAndCount;
};


#endif //SRC_LOAD_COMMAND_H
