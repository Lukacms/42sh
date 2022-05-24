/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** ctrl_l_handler
*/

#include "mysh.h"

int ctrl_l_handler(shell_t *shell)
{
    char *cmd[] = {"clear", "-x", NULL};

    if (!shell)
        return NOT_FOUND;
    analyse_cmd(cmd, shell);
    return SUCCESS;
}
