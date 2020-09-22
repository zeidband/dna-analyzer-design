//
// Created by Sara a on 9/22/20.
//

#ifndef SRC_I_PARAMS_H
#define SRC_I_PARAMS_H

#include <string>

typedef enum {
    E_WRONG,
    E_OK
} E_OK_PARAMS;


class IParams {
public:
    virtual std::string& getSequence() = 0;

    virtual std::string& getName() = 0;

    virtual bool isOk() = 0;
};


#endif //SRC_I_PARAMS_H
