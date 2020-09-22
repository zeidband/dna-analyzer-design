//
// Created by a on 9/16/20.
//

#ifndef SRC_SLICE_H
#define SRC_SLICE_H

#include <map>
#include "../i_command.h"

class Slice : public ICommand {
public:
    virtual void isOk(Parser& args);

    virtual bool run(Parser& input, IWrite* outputPrint);

    typedef std::map<std::string, size_t> sequenceName;

protected:
    void isCorrectArgs(Parser& args);

    void addName(Parser& args);

    void isNumbers(Parser &args);

    static sequenceName _sequenceFilesAndCount;

    bool _inPlace;
};


#endif //SRC_SLICE_H
