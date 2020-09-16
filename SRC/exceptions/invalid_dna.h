//
// Created by a on 9/16/20.
//

#ifndef SRC_INVALID_DNA_H
#define SRC_INVALID_DNA_H

#include <exception>

class InvalidDna : public std::exception {
public:
    virtual const char* what() const throw();
};


#endif //SRC_INVALID_DNA_H
