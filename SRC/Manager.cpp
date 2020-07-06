//
// Created by a on 7/5/20.
//

#include "Manager.h"
#include "key_board_reader.h"
#include "file_reader.h"
#include "console_writer.h"
#include "file_writer.h"
#include "command_line_interface.h"
#include "parser.h"

void Manager::start() {
    IRead *read = reinterpret_cast<IRead *>(new KeyBoardReader);
    IWrite *write = reinterpret_cast<IWrite *>(new ConsoleWriter);
    ICommand *command;
    Parser* current_command;

    do {
        write->write("\ncmd >> ");
//        current_command = factory();
//        current_command = read->read();


    } while(!command->run(current_command, write));

}
