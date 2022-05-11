/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** add_redirect_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static void init_node(red_node_t *node)
{
    node->head = NULL;
    node->size = 0;
    node->prev_red = R_NOTHING;
    node->next_red = R_NOTHING;
    node->prev = node;
    node->next = node;
}

static void put_node_in_list(red_node_t *node, split_node_t *split)
{
    if (!split->head)
        split->head = node;
    else {
        node->prev = split->head->prev;
        node->next = split->head;
        split->head->prev->next = node;
        split->head->prev = node;
    }
}

int add_redirect_node(split_node_t *split, char *cmd, char *delim)
{
    red_node_t *node = NULL;

    if (!split || !cmd || !(node = malloc(sizeof(red_node_t))))
        return FAILURE;
    init_node(node);
    if (info_red_node(node, cmd, delim) != SUCCESS)
        return FAILURE;
    if (split->size > 0)
        node->prev_red = split->head->prev->next_red;
    put_node_in_list(node, split);
    split->size += 1;
    return SUCCESS;
}
