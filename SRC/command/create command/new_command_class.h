//
// Created by a on 7/6/20.
//

#ifndef SRC_NEW_COMMAND_CLASS_H
#define SRC_NEW_COMMAND_CLASS_H

#include "../command_line_interface.h"

class NewCommandClass : public ICommand {
public:
    NewCommandClass(Parser* args);

    bool run(Parser* input, IWrite* outputPrint);

protected:
    bool isDna(std::string &basicString);
};


#endif //SRC_NEW_COMMAND_CLASS_H
