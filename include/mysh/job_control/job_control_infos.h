/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** job_control
*/

#ifndef JOB_CONTROL_INFOS_H_
    #define JOB_CONTROL_INFOS_H_

    #include <getopt.h>

    #define OPT_JOBS_STRING "prsl"

    #define JOB_INIT_CORRECT 0

typedef enum{
    EXITED,
    STOPPED,
    RUNNING,
} status_t;

typedef struct job_infos_s {
    bool only_stopped;
    bool only_running;
    bool only_pid;
    bool more_informations;
} job_infos_t;

typedef struct job_control_s {
    pid_t pid;
    char **args;
    status_t status;
    struct job_control_s *next;
} job_control_t;

typedef struct job_s {
    job_infos_t infos;
    job_control_t *control;
} job_t;

#endif /* !JOB_CONTROL_INFOS_H_ */
