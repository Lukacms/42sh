/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** terminal
*/

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "mysh.h"

int init_terminal(shell_t *shell)
{
    env_node_t *term = find_variable_by_name(shell, "TERM");

    if (!(term = find_variable_by_name(shell, "TERM")))
        return FAILURE;
    if ((tgetent(NULL, term->var_value)) < 0)
        return FAILURE;
    if ((tcgetattr(STDIN_FILENO, &shell->termios)) < 0)
        return FAILURE;
    shell->termios.c_lflag = (ECHO | IEXTEN | ISIG);
    shell->termios.c_cc[VMIN] = 1;
    shell->termios.c_cc[VTIME] = 0;
    shell->termios.c_cc[VEOF] = 4;
    shell->termios.c_cc[VERASE] = '\b';
    shell->termios.c_cc[VSUSP] = 26;
    shell->termios.c_cc[VINTR] = 3;
    shell->termios.c_iflag = BRKINT | ICRNL | IXON;
    shell->termios.c_oflag = ONLCR | ONOCR | OPOST | OFDEL;
    if ((tcsetattr(STDIN_FILENO, TCSADRAIN, &shell->termios)) < 0)
        return FAILURE;
    return SUCCESS;
}
