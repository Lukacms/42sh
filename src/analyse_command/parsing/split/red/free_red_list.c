/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** free_red_list
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

void free_red_list(split_node_t *split)
{
    red_node_t *anchor = NULL;
    red_node_t *tmp = NULL;

    if (!split || !split->head)
        return;
    anchor = split->head;
    tmp = split->head;
    for (unsigned int i = 0; i < split->size; i++) {
        anchor = anchor->next;
        free_pipe_list(tmp);
        free(tmp);
        tmp = anchor;
    }
}
