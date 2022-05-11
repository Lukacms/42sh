/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** find_variable_by_name
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

env_node_t *find_variable_by_name(shell_t *shell, char *name)
{
    env_node_t *node = NULL;

    if (!shell || !(node = shell->env.head))
        return NULL;
    for (unsigned int i = 0; i < shell->env.size; i++) {
        if (my_strcmp(node->var_name, name) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}
