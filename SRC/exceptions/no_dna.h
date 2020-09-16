//
// Created by a on 9/16/20.
//

#ifndef SRC_NO_DNA_H
#define SRC_NO_DNA_H

#include <exception>

class NoDna : public std::exception {
public:
    virtual const char* what() const throw();
};


#endif //SRC_NO_DNA_H
