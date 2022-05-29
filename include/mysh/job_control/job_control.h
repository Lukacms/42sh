/*
** EPITECH PROJECT, 2022
** job_control
** File description:
** job_control
*/

#ifndef JOB_CONTROL_H_
    #define JOB_CONTROL_H_

    #include "mysh/infos.h"

/*
* @brief init job part for shell
*
* @param job
* @return int
*/
int init_job(job_t *job);

/*
* @brief check for options of jobs command
*
* @param cmd
* @param shell
* @return int
*/
int check_jobs(char *cmd, shell_t *shell);

/*
* @brief add job in linked list
*
* @param job_control
* @param args
* @param pid
* @return int
*/
int add_job(job_control_t **job_control, char *const args[], int pid);

/*
* @brief set job to exited value
*
* @param job_control
* @param pid
* @param status
* @return int
*/
int remove_job(job_control_t **job_control, int pid, status_t status);

#endif /* !JOB_CONTROL_H_ */
