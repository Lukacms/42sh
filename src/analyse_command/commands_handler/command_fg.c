/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command_fg
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "mysh.h"
#include "my.h"

static int find_nb_stopped(job_control_t *tmp)
{
    int count = 0;

    while (tmp) {
        if (tmp->status == STOPPED)
            ++count;
        tmp = tmp->next;
    }
    return count;
}

static int loop_jobs(job_control_t *tmp, int nb_stopped)
{
    int temp_pid = 0;
    int count = 0;
    char **save = NULL;

    if (!tmp)
        return 0;
    while (tmp) {
        if (tmp->status == STOPPED) {
            temp_pid = tmp->pid;
            ++count;
        }
        if (nb_stopped == count)
            save = dup_array(tmp->args);
        tmp = tmp->next;
    }
    for (int i = 0; save[i]; i++)
        my_printf("%s ", save[i]);
    my_printf("\n");
    return temp_pid;
}

static int get_last_stopped_pid(job_control_t **jobs)
{
    job_control_t *tmp = NULL;
    int nb_stopped = 0;
    int temp_pid = 0;

    if (!jobs)
        return -1;
    tmp = (*jobs);
    nb_stopped = find_nb_stopped(tmp);
    temp_pid = loop_jobs(tmp, nb_stopped);
    return temp_pid;
}

int cmd_handler_fg(char __attribute__((unused))**array, shell_t *shell)
{
    int last_pid = 0;
    int wstatus = 0;

    if (!array || !shell)
        return FAILURE;
    last_pid = get_last_stopped_pid(&shell->job.control);
    if (last_pid == -1)
        return FAILURE;
    setpgid(last_pid, last_pid);
    tcsetpgrp(shell_fd, last_pid);
    kill(last_pid, SIGCONT);
    waitpid(last_pid, &wstatus, WUNTRACED);
    if (!WIFSTOPPED(wstatus))
        remove_job(&shell->job.control, last_pid, EXITED);
    else {
        my_printf("\nSuspended\n");
        remove_job(&shell->job.control, last_pid, STOPPED);
    }
    tcsetpgrp(shell_fd, getpid());
    return SUCCESS;
}
