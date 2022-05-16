/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** double_left_redirect
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static void forking_job(char *str, int *fd)
{
    size_t n = 0;
    ssize_t size = 0;
    char *cmp = NULL;

    while (size > -1) {
        my_printf("? ");
        size = getline(&cmp, &n, stdin);
        cmp[size - 1] = '\0';
        if (my_strcmp(cmp, str) == SUCCESS)
            break;
        else {
            write(fd[1], cmp, size);
            write(fd[1], "\n", 1);
        }
    }
    exit(SUCCESS);
}

static void input_loop(char *str, shell_t *shell)
{
    int fd[2] = {0};
    pid_t cpid = 0;
    int status = 0;

    if (pipe(fd) < 0)
        return;
    if ((cpid = fork()) < 0)
        return;
    else if (cpid == 0)
        forking_job(str, fd);
    waitpid(cpid, &status, WUNTRACED);
    close(fd[1]);
    shell->is_input = fd[0];
}

int double_left_redirect(red_node_t *node, split_node_t *split,
    shell_t __attribute__((unused)) *shell)
{
    int status = 0;
    red_node_t *concate = NULL;

    if (!node || !split)
        return status;
    concate = split->head;
    if (check_errors_left(node, concate, shell) != SUCCESS)
        return FAILURE;
    concate = node->prev;
    input_loop(node->head->cmd[0], shell);
    concate->head->prev->cmd = concate_arrays(concate->head->prev->cmd,
        node->head->cmd + 1);
    concate_nodes(concate, node);
    return status;
}
