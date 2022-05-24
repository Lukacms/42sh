/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** terminal
*/

#include "mysh.h"
#include <termios.h>
#include <unistd.h>

int my_terminal(shell_t *shell)
{
    struct termios termios;
    char *term_v = NULL;
    env_node_t *term = find_variable_by_name(shell, "TERM");

    term_v = getenv("TERM");
    if ((tgetent(NULL, term_v)) < 0)
        return 84;
    if ((tcgetattr(STDIN_FILENO, &termios)) < 0)
        return FAILURE;
    termios.c_lflag &= ~(ICANON | ECHO | IEXTEN);
    termios.c_cc[VMIN]  = 1;
    termios.c_cc[VTIME] = 0;
    if ((tcsetattr(STDIN_FILENO, TCSADRAIN, &termios)) < 0)
        return FAILURE;
    return 0;
}
