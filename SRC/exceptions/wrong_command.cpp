//
// Created by a on 9/16/20.
//

#include "wrong_command.h"

const char *WrongCommand::what() const throw() {
    return "WrongCommand:: There is no such command, try again!!";
}
