//
// Created by a on 7/5/20.
//

#ifndef SRC_FILE_WRITER_H
#define SRC_FILE_WRITER_H

#include "i_write.h"

class FileWriter : public IWrite{
public:
    void write(std::string);
};


#endif //SRC_FILE_WRITER_H
