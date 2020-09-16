//
// Created by a on 9/16/20.
//

#ifndef SRC_WRONG_COMMAND_H
#define SRC_WRONG_COMMAND_H

#include <exception>

class WrongCommand : public std::exception {
public:
    virtual const char* what() const throw();
};


#endif //SRC_WRONG_COMMAND_H
