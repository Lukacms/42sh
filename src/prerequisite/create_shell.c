/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** create_shell
*/

#include <stdlib.h>
#include "mysh.h"

static void init_shell(shell_t *shell)
{
    shell->aliases = (alias_t){0};
    shell->cmd = (parsing_infos_t){0};
    shell->env = (env_t){0};
    shell->finished = false;
    shell->history = (history_t){0};
    shell->is_input = 0;
    shell->is_output = 0;
    shell->path = (path_t){0};
    shell->redirect = false;
}

int create_shell(shell_t *shell, char * const env[])
{
    if (!shell)
        return FAILURE;
    init_shell(shell);
    if (create_env_list(env, shell) != SUCCESS)
        return FAILURE;
    if (init_history(&shell->history) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
