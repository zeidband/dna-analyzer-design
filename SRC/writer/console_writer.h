//
// Created by a on 7/5/20.
//

#ifndef SRC_CONSOLE_WRITER_H
#define SRC_CONSOLE_WRITER_H


#include "i_write.h"

class ConsoleWriter : public IWrite {
public:
    void write(std::string output);
};


#endif //SRC_CONSOLE_WRITER_H
