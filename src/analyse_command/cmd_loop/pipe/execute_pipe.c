/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** execute_pipe
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static void deal_with_fds(int **fd, unsigned int size, bool prev, bool next)
{
    for (unsigned int i = 0; fd[i]; i++) {
        if (prev == true && i == size - 1) {
            dup2(fd[i][0], STDIN_FILENO);
            close(fd[i][1]);
            continue;
        }
        if (next == true && i == size) {
            dup2(fd[i][1], STDOUT_FILENO);
            close(fd[i][0]);
            continue;
        }
        close(fd[i][0]);
        close(fd[i][1]);
    }
}

int execute_pipe(pipe_node_t *node, int **fd, unsigned int i, shell_t *shell)
{
    int status = 0;
    char **cmd = NULL;
    char **tmp = NULL;

    if (!node || !fd)
        return ERROR_REDIRECT;
    if (!node->cmd || !node->cmd[0]) {
        my_printf("Invalid null command.\n");
        return ERROR_REDIRECT;
    }
    deal_with_fds(fd, i, node->prev_pipe, node->next_pipe);
    if ((tmp = magic_loop(node, shell)))
        cmd = concate_arrays(node->cmd, tmp);
    status = analyse_cmd((cmd ? cmd : node->cmd), shell);
    free_array((void **)tmp);
    free_array((void **)cmd);
    return status;
}
