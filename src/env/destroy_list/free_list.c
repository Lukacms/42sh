/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** free_list
*/

#include <stdlib.h>
#include "mysh.h"

static void free_node_elements(env_node_t *node)
{
    if (node->var_name)
        free(node->var_name);
    if (node->var_value)
        free(node->var_value);
}

void free_list(shell_t *shell)
{
    env_node_t *tmp = shell->env.head;
    env_node_t *anchor = shell->env.head;

    for (unsigned int i = 0; i < shell->env.size; i++) {
        anchor = anchor->next;
        free_node_elements(tmp);
        free(tmp);
        tmp = anchor;
    }
    shell->env.size = 0;
    shell->env.head = NULL;
}
