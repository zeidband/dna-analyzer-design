//
// Created by a on 7/5/20.
//

#ifndef SRC_KEY_BOARD_READER_H
#define SRC_KEY_BOARD_READER_H


#include "reader.h"

class KeyBoardReader : public Reader {
public:
    virtual std::string read();
};


#endif //SRC_KEY_BOARD_READER_H
