/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** init_job
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int init_job(job_t *job)
{
    if (!job)
        return FAILURE;
    job->infos.only_pid = 0;
    job->infos.only_running = 0;
    job->infos.only_stopped = 0;
    job->infos.more_informations = 0;
    job->control = NULL;
    return JOB_INIT_CORRECT;
}
