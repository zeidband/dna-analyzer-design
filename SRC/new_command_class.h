//
// Created by a on 7/6/20.
//

#ifndef SRC_NEW_COMMAND_CLASS_H
#define SRC_NEW_COMMAND_CLASS_H

#include "i_create_commands.h"

class NewCommandClass : public ICreateCommands {
public:
    NewCommandClass(Parser*);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    bool isDna(std::string &basicString);
};


#endif //SRC_NEW_COMMAND_CLASS_H
