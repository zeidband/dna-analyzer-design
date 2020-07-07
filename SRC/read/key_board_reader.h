//
// Created by a on 7/5/20.
//

#ifndef SRC_KEY_BOARD_READER_H
#define SRC_KEY_BOARD_READER_H


#include "../read/reader.h"

class KeyBoardReader : public Reader {
public:
    virtual std::string& read(std::string& inputFrom);
};


#endif //SRC_KEY_BOARD_READER_H
