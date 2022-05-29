/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** execute_binary
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <errno.h>
#include "mysh.h"
#include "my.h"

pid_t fgpid;

static void set_filenos(shell_t *shell)
{
    if (shell->is_input > 0)
        dup2(shell->is_input, STDIN_FILENO);
    if (shell->is_output > 0)
        dup2(shell->is_output, STDOUT_FILENO);
}

static void reset_signals_to_default(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
    signal(SIGCHLD, SIG_DFL);
}

static int after_exec(shell_t *shell, char *const args[], pid_t *cpid,
int *status)
{
    tcsetpgrp(shell_fd, (*cpid));
    add_job(&shell->job.control, args, (*cpid));
    fgpid = (*cpid);
    waitpid((*cpid), status, WUNTRACED);
    display_possible_err(shell, (*status), (*cpid));
    tcsetpgrp(shell_fd, my_pgid);
    return (*status);
}

int execute_binary(char const *cmd, char *const args[], char *const env[],
shell_t *shell)
{
    int status = access(cmd, F_OK);
    pid_t cpid = 0;

    if (status < 0)
        return UNKNOWN;
    if ((cpid = fork()) < 0)
        return SUCCESS;
    if (cpid == 0) {
        setpgid(cpid, cpid);
        tcsetpgrp(shell_fd, getpid());
        reset_signals_to_default();
        if (shell->redirect == true)
            set_filenos(shell);
        execve(cmd, args, env);
        display_errno(cmd);
        exit(0);
    }
    status = after_exec(shell, args, &cpid, &status);
    return status;
}
