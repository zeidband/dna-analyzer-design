//
// Created by a on 7/5/20.
//

#include "console_reader.h"

std::string& ConsoleReader::read(std::string& inputFrom, size_t readSomeLines /*= 0*/) {
    getline(std::cin, _input);
    return _input;
}
