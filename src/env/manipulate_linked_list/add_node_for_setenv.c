/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** add_node_for_setenv
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void put_node_in_list(shell_t *shell, env_node_t *node)
{
    if (!shell->env.head)
        shell->env.head = node;
    else {
        node->prev = shell->env.head->prev;
        node->next = shell->env.head;
        shell->env.head->prev->next = node;
        shell->env.head->prev = node;
    }
}

static int add_new_variable(shell_t *shell, char *name, char *value)
{
    env_node_t *node = malloc(sizeof(env_node_t));

    if (!node)
        return FAILURE;
    node->var_name = my_strdup(name);
    node->var_value = my_strdup(value);
    node->next = node;
    node->prev = node;
    put_node_in_list(shell, node);
    shell->env.size += 1;
    return SUCCESS;
}

static int modify_variable_value(env_node_t *node, char *value)
{
    if (node->var_value != NULL)
        free(node->var_value);
    node->var_value = my_strdup(value);
    return SUCCESS;
}

int add_node_for_setenv(shell_t *shell, char *name, char *value)
{
    env_node_t *node = find_variable_by_name(shell, name);

    if (!node)
        return add_new_variable(shell, name, value);
    return modify_variable_value(node, value);
}
