//
// Created by a on 7/8/20.
//

#ifndef SRC_QUIT_COMMAND_H
#define SRC_QUIT_COMMAND_H

#include "../i_command.h"

class Quit : public ICommand {
public:
    bool run(Parser* input, IWrite* outputPrint) { return true; }
};


#endif //SRC_QUIT_COMMAND_H
