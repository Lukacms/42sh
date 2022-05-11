/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** replace_variable_value
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int replace_variable_value(shell_t *shell, char *name, char *value)
{
    env_node_t *node = find_variable_by_name(shell, name);

    if (!node)
        return add_node_for_setenv(shell, name, value);
    if (node->var_value)
        free(node->var_value);
    node->var_value = my_strdup(value);
    return SUCCESS;
}
