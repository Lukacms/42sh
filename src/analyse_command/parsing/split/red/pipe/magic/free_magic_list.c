/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** free_magic_list
*/

#include <stdlib.h>
#include "mysh.h"

void free_magic_list(pipe_node_t *pipe)
{
    magic_node_t *anchor = NULL;
    magic_node_t *tmp = NULL;

    if (!pipe || !(anchor = pipe->head))
        return;
    for (unsigned int i = 0; i < pipe->size; i += 1) {
        tmp = anchor;
        anchor = anchor->next;
        if (tmp->cmd)
            free(tmp->cmd);
        free(tmp);
    }
    pipe->head = NULL;
    pipe->size = 0;
}
