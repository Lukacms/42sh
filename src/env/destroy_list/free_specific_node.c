/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** free_specific_node
*/

#include <stdlib.h>
#include "mysh.h"

void free_specific_node(shell_t *shell, char *to_find)
{
    env_node_t *node = find_variable_by_name(shell, to_find);

    if (!node)
        return;
    if (node == shell->env.head)
        shell->env.head = shell->env.head->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->var_name);
    if (node->var_value)
        free(node->var_value);
    shell->env.size -= 1;
    if (shell->env.size == 0)
        shell->env.head = NULL;
    free(node);
}
