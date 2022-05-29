/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** error
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

void display_possible_err(shell_t *shell, int status, int pid)
{
    if (WIFSTOPPED(status)) {
        my_printf("^Z\nSuspended\n");
        remove_job(&shell->job.control, pid, STOPPED);
    }
    if (WIFEXITED(status)) {
        remove_job(&shell->job.control, pid, EXITED);
        return;
    }
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE)
            my_printf("Floating exception");
        else
            my_printf("%s", strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        my_printf("\n");
    }
}

void display_errno(char const *cmd)
{
    if (errno == ENOEXEC)
        my_printf("%s: Exec format error. Wrong Architecture.\n", cmd);
    else
        my_printf("%s: %s.\n", cmd, strerror(errno));
}
