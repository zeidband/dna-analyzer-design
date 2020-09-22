//
// Created by a on 7/8/20.
//

#ifndef SRC_QUIT_H
#define SRC_QUIT_H

#include "../i_command.h"

class Quit : public ICommand {
public:
    void setArgs(Parser& args) {}

    bool run(IWrite* outputPrint) { return true; }
};


#endif //SRC_QUIT_H
