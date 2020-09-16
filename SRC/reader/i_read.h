//
// Created by a on 7/5/20.
//

#ifndef SRC_I_READ_H
#define SRC_I_READ_H

#include <iostream>
#include <string>

class IRead {
public:
    virtual ~IRead() {}

    virtual std::string& read(std::string& inputFrom = ((std::string&)""), size_t readSomeLines = 0) = 0;
};


#endif //SRC_I_READ_H
