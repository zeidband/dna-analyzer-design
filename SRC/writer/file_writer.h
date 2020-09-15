//
// Created by a on 7/5/20.
//

#ifndef SRC_FILE_WRITER_H
#define SRC_FILE_WRITER_H

#include "i_write.h"

class FileWriter : public IWrite{
public:
    explicit FileWriter(const std::string& name = "output.txt") : _fileName(name) {}

    void write(std::string);

private:
    const std::string _fileName;
};


#endif //SRC_FILE_WRITER_H
