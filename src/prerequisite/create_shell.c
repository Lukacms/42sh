/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** create_shell
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static void init_signal(void)
{
    set_shellfd(STDERR_FILENO);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    set_mypid(getpid());
    set_mypgid(getpid());
    setpgid(*(get_mypid()), *(get_mypgid()));
    tcsetpgrp(*(get_shell_fd()), *(get_mypgid()));
}

static void init_shell(shell_t *shell)
{
    shell->aliases = (alias_t){0};
    shell->cmd = (parsing_infos_t){0};
    shell->env = (env_t){0};
    shell->finished = false;
    shell->history = (history_t){0};
    shell->job = (job_t){0};
    shell->is_input = 0;
    shell->is_output = 0;
    shell->path = (path_t){0};
    shell->redirect = false;
    shell->termios = (termios_t){0};
    shell->special = (special_variables_infos_t){0};
}

int create_shell(shell_t *shell, char * const env[], char * const argv[])
{
    if (!shell)
        return FAILURE;
    init_signal();
    init_shell(shell);
    if (!(shell->special.current_script = my_strdup(argv[0])))
        return FAILURE;
    if (create_env_list(env, shell) != SUCCESS)
        return FAILURE;
    if (init_history(&shell->history) != SUCCESS)
        return FAILURE;
    if (init_job(&shell->job) != SUCCESS)
        return FAILURE;
    if (init_terminal(shell) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
