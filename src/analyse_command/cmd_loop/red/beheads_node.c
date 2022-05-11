/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** beheads_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static void free_node(pipe_node_t *node)
{
    if (node->cmd)
        free_array((void **)node->cmd);
    free(node);
}

int beheads_node(red_node_t *red)
{
    pipe_node_t *node = NULL;

    if (!red || !red->head)
        return FAILURE;
    node = red->head;
    red->head = red->head->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free_node(node);
    red->size -= 1;
    return SUCCESS;
}
