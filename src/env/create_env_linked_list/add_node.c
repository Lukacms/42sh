/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** add_node
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void put_infos_in_node(char *const env_line, env_node_t *node)
{
    int i = 0;

    for (; env_line[i] != '='; i++);
    node->var_name = my_strndup(env_line, i);
    node->var_value = my_strdup(env_line + i + 1);
}

static void put_node_in_list(shell_t *shell, env_node_t *node)
{
    if (!(shell->env.head))
        shell->env.head = node;
    else {
        node->prev = shell->env.head->prev;
        node->next = shell->env.head;
        shell->env.head->prev->next = node;
        shell->env.head->prev = node;
    }
}

int add_node(shell_t *shell, char *const env_line)
{
    env_node_t *new_node = NULL;

    if (!shell || !env_line)
        return FAILURE;
    new_node = malloc(sizeof(env_node_t));
    if (!new_node)
        return FAILURE;
    put_infos_in_node(env_line, new_node);
    new_node->prev = new_node;
    new_node->next = new_node;
    put_node_in_list(shell, new_node);
    shell->env.size += 1;
    return SUCCESS;
}
