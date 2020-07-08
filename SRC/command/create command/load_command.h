//
// Created by a on 7/7/20.
//

#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H

#include "../command_line_interface.h"
#include <map>

typedef std::map<std::string, size_t> sequenceName;

class Load : public ICommand {
public:
    Load(Parser& args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    bool isDna(std::string &dna);

    sequenceName _sequenceFilesAndCount;
};


#endif //SRC_LOAD_COMMAND_H
