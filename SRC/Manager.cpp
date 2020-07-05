//
// Created by a on 7/5/20.
//

#include "Manager.h"
#include "key_board_reader.h"
#include "console_writer.h"
#include "command_line_interface.h"

void Manager::start() {
    IRead *read = reinterpret_cast<IRead *>(new KeyBoardReader);
    IWrite *write = reinterpret_cast<IWrite *>(new ConsoleWriter);
    ICommand *command;
    std::string current_command;

    while(true) {
        write->write("\ncmd >> ");
        current_command = read->read();
//        factory(command).run(write);

//      for checking
        write->write(current_command);





        //infinite loop
        char i = 0;
        if( i++ == 1000 )
            break;
    }
}
