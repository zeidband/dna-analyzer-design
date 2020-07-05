//
// Created by a on 7/5/20.
//

#ifndef SRC_READER_H
#define SRC_READER_H

#include "i_read.h"

class Reader : public IRead {
protected:
    std::string _input;
};


#endif //SRC_READER_H
