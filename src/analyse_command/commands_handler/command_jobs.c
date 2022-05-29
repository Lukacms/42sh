/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command_jobs
*/

#include "mysh.h"
#include "my.h"

static const char *status_jobs_array[3] = {
    "Suspended",
    "Running",
    NULL
};

static char detect_last_job(job_control_t *job_control, int pid,
status_t status)
{
    job_control_t *tmp = NULL;
    int temp_pid = 0;
    char sign = ' ';

    if (!job_control)
        return sign;
    tmp = job_control;
    while (tmp) {
        if (tmp->status == status)
            temp_pid = tmp->pid;
        tmp = tmp->next;
    }
    if (temp_pid == pid) {
        sign = ((status == STOPPED) ? ('+') : ('-'));
        return sign;
    }
    return sign;
}

int cmd_handler_jobs(char __attribute__((unused))**array, shell_t *shell)
{
    int i = 1;
    job_control_t *jobs = NULL;

    if (!shell || !(jobs = shell->job.control))
        return ERROR_BUILTIN;
    while (jobs != NULL) {
        if (jobs->status != EXITED) {
            my_printf("[%d]  ", i);
            my_printf("%c ", detect_last_job(shell->job.control, jobs->pid, jobs->status));
            my_printf("%d %s", jobs->pid, status_jobs_array[jobs->status - 1]);
            if (shell->job.infos.more_informations) {
                my_printf("\t\t\t\t");
                for (int i = 0; jobs->args[i]; i++)
                    my_printf("%s ", jobs->args[i]);
            }
            my_printf("\n");
            ++i;
        }
        jobs = jobs->next;
    }
    shell->job.infos.more_informations = 0;
    shell->job.infos.only_pid = 0;
    shell->job.infos.only_running = 0;
    shell->job.infos.only_stopped = 0;
    return SUCCESS;
}
