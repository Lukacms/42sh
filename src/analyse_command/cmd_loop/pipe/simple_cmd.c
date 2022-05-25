/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** simple_cmd
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int simple_cmd(pipe_node_t *pipe, shell_t *shell)
{
    int status = 0;

    if (!pipe || !shell)
        return NOT_FOUND;
    if (pipe->next_pipe || pipe->prev_pipe) {
        my_printf("Invalid null command.\n");
        return ERROR_REDIRECT;
    }
    shell->redirect = true;
    status = analyse_cmd(pipe->cmd, shell);
    return status;
}
