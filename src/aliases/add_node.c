/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** add_node
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void init_node(alias_node_t *node)
{
    node->name = NULL;
    node->value = NULL;
    node->prev = node;
    node->next = node;
}

static void put_node_in_list(alias_node_t *node, shell_t *shell)
{
    if (!shell->aliases.head)
        shell->aliases.head = node;
    else {
        node->prev = shell->aliases.head->prev;
        node->next = shell->aliases.head;
        shell->aliases.head->prev->next = node;
        shell->aliases.head->prev = node;
    }
}

int add_alias_node(char const *name, char * const value[], shell_t *shell)
{
    alias_node_t *node = NULL;

    if (!name || !value || !shell)
        return FAILURE;
    if (!(node = malloc(sizeof(alias_node_t))))
        return FAILURE;
    init_node(node);
    node->name = my_strdup(name);
    node->value = dup_array(value);
    if (!node->name || !node->value)
        return FAILURE;
    put_node_in_list(node, shell);
    shell->aliases.size += 1;
    return SUCCESS;
}
