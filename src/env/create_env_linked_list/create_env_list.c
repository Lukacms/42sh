/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** create_env_list
*/

#include <stdbool.h>
#include <stdlib.h>
#include "mysh.h"

int create_env_list(char *const env[], shell_t *shell)
{
    if (!shell)
        return FAILURE;
    if (!env)
        return FAILURE;
    for (int i = 0; env[i]; i++) {
        if (add_node(shell, env[i]) != 0)
            return FAILURE;
    }
    return SUCCESS;
}
