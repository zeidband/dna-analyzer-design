//
// Created by Sara a on 7/7/20.
//

#include "load.h"
#include "../../dna/container_dna.h"
#include "../../reader/file_reader.h"
#include "new.h"
#include <cstring>
#include <sstream>
#include "../../exceptions/invalid_dna.h"
#include "../../exceptions/too_many_parameters.h"
#include "../../exceptions/few_parameters.h"
#include "../../exceptions/wrong_syntax.h"


bool Load::run(IWrite *outputPrint) {
    if ( params.isOk() ) {
        ContainerDna::printDnaById(outputPrint, ContainerDna::addDna(params.getSequence(), params.getName()), false);
    }

    else {
        outputPrint->write("wrong in load parameters\n");
        outputPrint->write(params.getMessage());
    }

    return false;
}

void Load::setArgs(Parser &args) {
    params = args;
}

