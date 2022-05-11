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

    shell->redirect = true;
    status = analyse_cmd(pipe->cmd, shell);
    return status;
}
