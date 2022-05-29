/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** manage_jobs
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int remove_job(job_control_t **job_control, int pid, status_t status)
{
    job_control_t *lnode = NULL;

    if (!(*job_control))
        return FAILURE;
    lnode = *job_control;
    while (lnode) {
        if (lnode->pid == pid)
            lnode->status = status;
        lnode = lnode->next;
    }
    return SUCCESS;
}

int add_job(job_control_t **job_control, char *const args[], int pid)
{
    job_control_t *node = malloc(sizeof(job_control_t));
    job_control_t *lnode = NULL;

    if (!node)
        return FAILURE;
    node->args = dup_array(args);
    node->pid = pid;
    node->status = RUNNING;
    node->next = NULL;
    if (!(*job_control)) {
        *job_control = node;
    } else {
        lnode = *job_control;
        while (lnode->next)
            lnode = lnode->next;
        lnode->next = node;
    }
    return SUCCESS;
}
