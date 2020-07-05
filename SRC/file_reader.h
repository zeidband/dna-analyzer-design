//
// Created by a on 7/5/20.
//

#ifndef SRC_FILE_READER_H
#define SRC_FILE_READER_H

#include "reader.h"
#include <fstream>

class FileReader : public Reader {
public:
    std::string read();
};


#endif //SRC_FILE_READER_H
