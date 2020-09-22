//
// Created by Sara a on 7/7/20.
//

#ifndef SRC_LOAD_H
#define SRC_LOAD_H

#include "../i_command.h"
#include "../params/command_params/load.h"


class Load : public ICommand {
public:
    bool run(IWrite* outputPrint);

    void setArgs(Parser& other);

private:
    LoadParams params;
};


#endif //SRC_LOAD_H
