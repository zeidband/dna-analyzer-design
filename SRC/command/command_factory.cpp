//
// Created by a on 7/6/20.
//

#include <iostream>
#include <cstring>
#include "command_factory.h"
#include "create command/new_command.h"
#include "create command/dup_command.h"
#include "create command/quit_command.h"


CommandFactory::~CommandFactory() {
    delete _command;
}


ICommand *CommandFactory::getCommand(Parser &command) {
    //check to under conditions
    //keep in list

    if(!strcmp(command._args[0].c_str(), "new")) {
        ICommand* temp = new New(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "load")) {
        ICommand* temp = new Load(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "dup")) {
        ICommand* temp = new Dup(command);
        delete _command;
        _command = temp;
    }

    else if(!strcmp(command._args[0].c_str(), "quit")) {
        ICommand* temp = new Quit;
        delete _command;
        _command = temp;
    }

    else
        throw std::invalid_argument("There is no such command");

    return _command;
}


//jump table
//
//typedef void (*Handler)(void);    /* A pointer to a handler function */
//
///* The functions */
//void func3 (void) { printf( "3\n" ); }
//void func2 (void) { printf( "2\n" ); }
//void func1 (void) { printf( "1\n" ); }
//void func0 (void) { printf( "0\n" ); }
//
//Handler jump_table[4] = {func0, func1, func2, func3};
//
//int main (int argc, char **argv) {
//    int value;
//
//    /* Convert first argument to 0-3 integer (modulus) */
//    value = ((atoi(argv[1]) % 4) + 4) % 4;
//
//    /* Call appropriate function (func0 thru func3) */
//    jump_table[value]();
//
//    return 0;
//}