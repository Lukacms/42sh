/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** check_jobs
*/

#include "mysh.h"
#include "my.h"

static int get_options(char flag, shell_t *shell)
{
    if (!shell)
        return FAILURE;
    switch (flag) {
        case 'p':
            shell->job.infos.only_pid = 1;
            break;
        case 'r':
            shell->job.infos.only_running = 1;
            break;
        case 's':
            shell->job.infos.only_stopped = 1;
            break;
        case 'l':
            shell->job.infos.more_informations = 1;
            break;
        default:
            return FAILURE;
    }
    return SUCCESS;
}

static int parse_jobs_cmd(char *cmd, shell_t *shell)
{
    char *optstring = OPT_JOBS_STRING;
    int opt = 0;
    int len = 0;
    char **args = NULL;

    if (!cmd || !shell)
        return FAILURE;
    if (my_strncmp(cmd, "jobs ", 5) != 0)
        return SUCCESS;
    if (!(args = str_to_array_choice(cmd, " ")))
        return FAILURE;
    len = array_len(args);
    optind = 1;
    while ((opt = getopt(len, args, optstring)) != -1) {
        if (get_options(opt, shell) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}

int check_jobs(char *cmd, shell_t *shell)
{
    if (!cmd || !shell)
        return FAILURE;
    if (parse_jobs_cmd(cmd, shell) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
