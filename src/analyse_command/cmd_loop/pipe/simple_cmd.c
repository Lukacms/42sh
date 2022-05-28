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
    char **cmd = NULL;
    char **tmp = NULL;

    if (!pipe || !shell)
        return NOT_FOUND;
    if (pipe->next_pipe || pipe->prev_pipe) {
        my_printf("Invalid null command.\n");
        return ERROR_REDIRECT;
    }
    shell->redirect = true;
    if ((tmp = magic_loop(pipe, shell)))
        cmd = concate_arrays(pipe->cmd, tmp);
    status = analyse_cmd((cmd ? cmd : pipe->cmd), shell);
    free_array((void **)cmd);
    free_array((void **)tmp);
    return status;
}
