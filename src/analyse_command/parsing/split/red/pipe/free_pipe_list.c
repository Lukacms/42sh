/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** free_pipe_list
*/

#include <stdlib.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static void free_node(pipe_node_t *node)
{
    if (node->cmd)
        free_array((void **)node->cmd);
    free_magic_list(node);
}

void free_pipe_list(red_node_t *red)
{
    pipe_node_t *anchor = NULL;
    pipe_node_t *tmp = NULL;

    if (!red || !red->head)
        return;
    anchor = red->head;
    tmp = red->head;
    for (unsigned int i = 0; i < red->size; i++) {
        anchor = anchor->next;
        free_node(tmp);
        free(tmp);
        tmp = anchor;
    }
    red->head = NULL;
    red->size = 0;
}
