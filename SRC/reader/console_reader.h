//
// Created by a on 7/5/20.
//

#ifndef SRC_CONSOLE_READER_H
#define SRC_CONSOLE_READER_H


#include "reader.h"

class ConsoleReader : public Reader {
public:
    virtual std::string& read(std::string& inputFrom, size_t readSomeLines /*= 0*/);
};


#endif //SRC_CONSOLE_READER_H
