//
// Created by a on 9/16/20.
//

#ifndef SRC_FEW_PARAMETERS_H
#define SRC_FEW_PARAMETERS_H

#include <exception>


class FewParameters : public std::exception {
public:
    FewParameters(const char* message="There are not enough arguments") : _message(message) { }

    virtual const char* what() const throw();

private:
    const char *_message;
};


#endif //SRC_FEW_PARAMETERS_H
