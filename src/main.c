// ***************************************************************************************
//    Project: Calculator in C
//    File: main.c
//    Date: 2024-07-24
//    Author: Navid Dezashibi
//    Contact: navid@dezashibi.com
//    Website: https://www.dezashibi.com | https://github.com/dezashibi
//    License:
//     Please refer to the LICENSE file, repository or website for more information about
//     the licensing of this work. If you have any questions or concerns,
//     please feel free to contact me at the email address provided above.
// ***************************************************************************************
// *  Description: refer to readme file.
// ***************************************************************************************

#include "colors.h"
#include "command.h"

def_invoke_fn_as(addition_fn)
{
    (void)argc;
    (void)argv;
    return 0;
}

static Command commands[] = {
    {"+", "adds 2 or more arguments together", addition_fn},
};

int main(int argc, char* argv[])
{
    puts("Welcome!");

    if (argc < 3)
    {
        puts(FG_RED "error: " COLOR_RESET "not enough number of arguments\n\t" FG_GREEN "./calc.exe <op> <...args>\n" COLOR_RESET);

        show_help(commands);

        return -1;
    }

    Command* cmd = get_command(argv[1], commands);

    if (cmd == NULL)
    {
        printf(FG_RED "error: " COLOR_RESET "command '%s' not found\n", argv[1]);

        show_help(commands);

        return -1;
    }

    printf("Help on %s: %s\n", cmd->name, cmd->help);

    return 0;
}
