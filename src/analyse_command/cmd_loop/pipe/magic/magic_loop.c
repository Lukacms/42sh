/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** magic_loop
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "mysh.h"
#include "my.h"

static char **fileno_in_array(FILE *fileno)
{
    char **infos = NULL;
    ssize_t size = 0;
    size_t count = 0;
    char *line = NULL;

    for (u_int i = 1; (size = getline(&line, &count, fileno)) != -1; i++) {
        infos = my_reallocarray(infos, i);
        if (line[size - 1] == '\n')
            line[size - 1] = '\0';
        infos[i - 1] = my_strdup(line);
        infos[i] = NULL;
    }
    free(line);
    fclose(fileno);
    return infos;
}

static void execute_loop(pipe_node_t *pip, int fd, shell_t *shell)
{
    magic_node_t *tmp = pip->head;
    unsigned int size = pip->size;

    if (!tmp)
        exit(SUCCESS);
    dup2(fd, STDOUT_FILENO);
    shell->cmd.head = NULL;
    shell->cmd.size = 0;
    for (unsigned int i = 0; i < size; i += 1) {
        get_commands(shell, tmp->cmd);
        tmp = tmp->next;
    }
    exit(SUCCESS);
}

char **magic_loop(pipe_node_t *pip, shell_t *shell)
{
    char **full = NULL;
    int fd[2] = {0};
    pid_t cpid = 0;
    int status = 0;
    FILE *fileno = NULL;

    if (!pip || !shell || pip->size == 0)
        return NULL;
    if (pipe(fd) < 0 || (cpid = fork()) < 0)
        return NULL;
    if (cpid == 0)
        execute_loop(pip, fd[1], shell);
    waitpid(cpid, &status, WUNTRACED);
    close(fd[1]);
    fileno = fdopen(fd[0], "r");
    return (full = fileno_in_array(fileno));
}
