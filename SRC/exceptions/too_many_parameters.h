//
// Created by a on 9/16/20.
//

#ifndef SRC_MANY_ARGUMENTS_H
#define SRC_MANY_ARGUMENTS_H

#include <exception>

class TooManyParameters : public std::exception {
public:
    TooManyParameters(const char* message="There are not enough arguments") : _message(message) { }

    virtual const char* what() const throw();

private:
    const char *_message;
};


#endif //SRC_MANY_ARGUMENTS_H
