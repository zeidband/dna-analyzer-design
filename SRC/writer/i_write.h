//
// Created by a on 7/5/20.
//

#ifndef SRC_I_WRITE_H
#define SRC_I_WRITE_H


#include <string>

class IWrite {
public:
    virtual ~IWrite() {}

    virtual void write(std::string) = 0;
};


#endif //SRC_I_WRITE_H
