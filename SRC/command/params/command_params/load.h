//
// Created by Sara a on 9/22/20.
//

#ifndef SRC_LOAD_PARAMS_H
#define SRC_LOAD_PARAMS_H

#include <map>
#include "../i_params.h"
#include "../../../manager/parser.h"

class LoadParams : public IParams {
public:
    virtual std::string& getSequence() { return _sequence; }

    virtual std::string& getName()     { return _name; }

    virtual std::string& getMessage()  { return _message; }

    virtual bool isOk()                { return _ok; };

    LoadParams& operator=(Parser& args);


    typedef std::map<std::string, size_t> sequenceName;

protected:
    void numOfParameters(size_t size);

    void isFileExist(std::string &fileName);

    void isDna(std::string &dna);

    void isCorrectName(std::string& name);

    void newName(std::string& fileName);

private:
    static sequenceName _sequenceFilesAndCount;

    std::string _sequence;

    std::string _name;

    E_OK_PARAMS _ok;

    std::string _message;
};


#endif //SRC_LOAD_H
