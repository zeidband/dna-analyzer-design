//
// Created by a on 9/16/20.
//

#ifndef SRC_WRONG_SYNTAX_H
#define SRC_WRONG_SYNTAX_H

#include <exception>

class WrongSyntax : public std::exception {
public:
    WrongSyntax(const char* message="") : _message(message) { }

    virtual const char* what() const throw();

private:
    const char *_message;
};


#endif //SRC_WRONG_SYNTAX_H
