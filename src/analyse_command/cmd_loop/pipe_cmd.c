/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** pipe_cmd
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int pipe_cmd_loop(red_node_t *red, shell_t *shell)
{
    int status = 0;

    if (!red || !shell)
        return status;
    if (red->size == 1)
        status = simple_cmd(red->head, shell);
    else
        status = loop_pipe(red, shell);
    return status;
}
