/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** ctrl_l_handler
*/

#include <unistd.h>
#include "mysh.h"

int ctrl_l_handler(shell_t *shell, char **line, int *n)
{
    char *cmd[] = {"clear", "-x", NULL};

    if (!shell)
        return NOT_FOUND;
    analyse_cmd(cmd, shell);
    display_prompt(shell->special.status, shell);
    write(STDOUT_FILENO, *line, *n);
    return SUCCESS;
}
