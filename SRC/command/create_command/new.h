//
// Created by Sara a on 7/6/20.
//

#ifndef SRC_NEW_H
#define SRC_NEW_H

#include "../i_command.h"
#include "../params/command_params/new.h"


class New : public ICommand {
public:
    bool run(IWrite* outputPrint);

    void setArgs(Parser& args);

private:
    NewParams params;
};


#endif //SRC_NEW_H
