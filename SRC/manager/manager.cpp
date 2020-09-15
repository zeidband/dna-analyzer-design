//
// Created by a on 7/5/20.
//

#include "manager.h"
#include "../reader/console_reader.h"
#include "../writer/console_writer.h"
#include "../command/i_command.h"
#include "parser.h"
#include "../command/command_factory.h"
#include "../dna/container_dna.h"

void Manager::start() {
    IRead *read = reinterpret_cast<IRead *>(new ConsoleReader);
    IWrite *write = reinterpret_cast<IWrite *>(new ConsoleWriter);
    ICommand *command;
    Parser current_command;
    CommandFactory factory;
    bool flag = false;

    while(!flag) {
        write->write("\n> cmd >> ");

        current_command = read->read();

        try {
            command = factory.getCommand(current_command);
        }

        catch(std::exception &ex) {
            write->write(ex.what());
            continue;
        }

        flag = (command->run(&current_command, write));
    }

    ContainerDna::deleteAll();
    delete read;
    delete write;
}
