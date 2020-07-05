//
// Created by a on 7/5/20.
//

#include "key_board_reader.h"

std::string KeyBoardReader::read() {
    getline(std::cin, _input);
    return _input;
}

