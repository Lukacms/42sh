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

static int err_pipe(red_node_t *red)
{
    pipe_node_t *pipe = red->head;

    if (!red->head) {
        my_printf(PIPE_NULL);
        return ERROR_REDIRECT;
    }
    for (unsigned int i = 0; i < red->size; i++) {
        if (!pipe->cmd || !(*pipe->cmd)) {
            my_printf(PIPE_NULL);
            return ERROR_REDIRECT;
        }
    }
    return SUCCESS;
}

int pipe_cmd_loop(red_node_t *red, shell_t *shell)
{
    int status = 0;

    if (!red || !shell)
        return status;
    if ((status = err_pipe(red)) != SUCCESS)
        return status;
    if (red->size == 1)
        status = simple_cmd(red->head, shell);
    else
        status = loop_pipe(red, shell);
    return status;
}
