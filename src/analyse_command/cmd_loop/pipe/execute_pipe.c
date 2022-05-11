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

static void deal_with_fds(int **fd, u_int size, bool prev, bool next)
{
    for (u_int i = 0; fd[i]; i++) {
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

int execute_pipe(pipe_node_t *node, int **fd, u_int i, shell_t *shell)
{
    int status = 0;

    if (!node || !fd)
        return status;
    if (!node->cmd || !node->cmd[0])
        return my_printf("Invalid null command.\n");
    deal_with_fds(fd, i, node->prev_pipe, node->next_pipe);
    status = analyse_cmd(node->cmd, shell);
    return status;
}
