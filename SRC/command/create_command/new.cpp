//
// Created by Sara a on 7/6/20.
//

#include "new.h"
#include "../../dna/container_dna.h"


bool New::run(IWrite* outputPrint) {
    if ( params.isOk() ) {
        ContainerDna::printDnaById(outputPrint, ContainerDna::addDna(params.getSequence(), params.getName()));
    }

    else {
        outputPrint->write("wrong in new parameters\n");
        outputPrint->write(params.getMessage());
    }

    return false;
}

void New::setArgs(Parser &args) {
    params = args;
}

