/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** loop_pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "my.h"

static int **pipe_array(unsigned int y)
{
    int **fd = NULL;

    if (!(fd = malloc(sizeof(int *) * (y + 1))))
        return NULL;
    for (unsigned int i = 0; i < y; i++) {
        if (!(fd[i] = malloc(sizeof(int) * 2)) || pipe(fd[i]) < 0)
            return NULL;
    }
    fd[y] = NULL;
    return fd;
}

static void close_pipes(int **fd)
{
    for (unsigned int i = 0; fd[i]; i++) {
        close(fd[i][0]);
        close(fd[i][1]);
    }
    free_array((void **)fd);
}

int loop_pipe(red_node_t *red, shell_t *shell)
{
    int status = 0;
    int **fd = NULL;
    pid_t cpid = 0;
    pipe_node_t *node = (red ? red->head : NULL);

    if (!node || !shell || !(fd = pipe_array(red->size - 1)))
        return status;
    for (unsigned int i = 0; i < red->size && status == SUCCESS; i++) {
        shell->redirect = (i == red->size - 1 ? true : false);
        if ((cpid = fork()) < 0)
            return status;
        if (cpid == 0) {
            status = execute_pipe(node, fd, i, shell);
            exit(status);
        }
        node = node->next;
    }
    close_pipes(fd);
    waitpid(cpid, &status, WUNTRACED);
    return status;
}
