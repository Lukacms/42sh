/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** create_env_list
*/

#include <stdbool.h>
#include <stdlib.h>
#include "mysh.h"

static void initialize_env_list(shell_t *shell)
{
    shell->env.head = NULL;
    shell->env.size = 0;
    shell->path.head = NULL;
    shell->path.size = 0;
    shell->cmd.head = NULL;
    shell->cmd.size = 0;
    shell->is_input = 0;
    shell->is_output = 0;
    shell->finished = false;
    shell->redirect = false;
    shell->aliases.head = NULL;
    shell->aliases.size = 0;
}

int create_env_list(char *const env[], shell_t *shell)
{
    if (!shell)
        return FAILURE;
    initialize_env_list(shell);
    if (!env)
        return FAILURE;
    for (int i = 0; env[i]; i++) {
        if (add_node(shell, env[i]) != 0)
            return FAILURE;
    }
    return SUCCESS;
}
