//
// Created by Sara a on 9/22/20.
//

#ifndef SRC_NEW_PARAMS_H
#define SRC_NEW_PARAMS_H

#include "../i_params.h"
#include "../../../manager/parser.h"

class NewParams : public IParams {
public:
    virtual std::string& getSequence() { return _sequence; }

    virtual std::string& getName()     { return _name; }

    virtual bool isOk()                { return _ok; };

    virtual std::string& getMessage() { return _message; }

    NewParams& operator=(Parser& args);

protected:
    void numOfParameters(size_t size);

    void isDna(std::string &dna);

    void isCorrectName(std::string& name);

    void newName();

private:
    std::string _sequence;

    std::string _name;

    E_OK_PARAMS _ok;

    std::string _message;
};


#endif //SRC_NEW_PARAMS_H
