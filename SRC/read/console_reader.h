//
// Created by a on 7/5/20.
//

#ifndef SRC_CONSOLE_READER_H
#define SRC_CONSOLE_READER_H


#include "../read/reader.h"

class ConsoleReader : public Reader {
public:
    virtual std::string& read(std::string& inputFrom);
};


#endif //SRC_CONSOLE_READER_H
