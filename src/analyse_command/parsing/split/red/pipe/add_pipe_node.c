/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** add_pipe_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static void init_node(pipe_node_t *node)
{
    node->cmd = NULL;
    node->next_pipe = false;
    node->prev_pipe = false;
    node->prev = node;
    node->next = node;
}

static void put_node_in_list(pipe_node_t *node, red_node_t *redirect)
{
    if (!redirect->head)
        redirect->head = node;
    else {
        node->prev = redirect->head->prev;
        node->next = redirect->head;
        redirect->head->prev->next = node;
        redirect->head->prev = node;
    }
}

int add_pipe_node(red_node_t *redirect, char *cmd, char *delim)
{
    pipe_node_t *node = NULL;

    if (!redirect || !(node = malloc(sizeof(pipe_node_t))))
        return FAILURE;
    init_node(node);
    if (info_in_pipe_node(node, cmd, delim) != SUCCESS)
        return FAILURE;
    if (redirect->size > 0)
        node->prev_pipe = redirect->head->prev->next_pipe;
    put_node_in_list(node, redirect);
    redirect->size += 1;
    return SUCCESS;
}
