/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** concate_nodes
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

int concate_nodes(red_node_t *concate, red_node_t *from)
{
    if (!concate || !from)
        return FAILURE;
    concate->head->prev->next = from->head->next;
    concate->head->prev->next_pipe = from->head->next_pipe;
    concate->head->prev = from->head->prev;
    from->head->next->prev = concate->head->prev;
    from->head->prev->next = concate->head;
    concate->size += from->size - 1;
    free_node(from->head);
    from->head = NULL;
    from->size = 0;
    return SUCCESS;
}
