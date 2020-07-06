//
// Created by a on 7/6/20.
//

#include "new_command_class.h"


new_command_class::new_command_class(Parser *) {
    //Correctness check on parser
}


bool new_command_class::run(Parser* input, IWrite* outputPrint) {
    // 1. add new seq to the list of the DNA
    outputPrint->write("in new command");
    return false;
}

