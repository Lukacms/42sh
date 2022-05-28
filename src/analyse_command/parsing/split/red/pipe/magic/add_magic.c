/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** add_magic
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void init_magic(magic_node_t *node)
{
    node->cmd = NULL;
    node->next = node;
    node->prev = node;
}

static int infos_in_magic(char *cmd, magic_node_t *node)
{
    int size = my_strlen(cmd);

    if (cmd[0] != MAGIC_QUOTE || cmd[size - 1] != MAGIC_QUOTE)
        return FAILURE;
    cmd[size - 1] = '\0';
    if (!(node->cmd = my_strdup(cmd + 1)))
        return FAILURE;
    return SUCCESS;
}

static void put_node_in_list(magic_node_t *node, pipe_node_t *pipe)
{
    if (!pipe->head)
        pipe->head = node;
    else {
        node->prev = pipe->head->prev;
        node->next = pipe->head;
        pipe->head->prev->next = node;
        pipe->head->prev = node;
    }
}

int add_magic(char *cmd, pipe_node_t *pipe)
{
    magic_node_t *node;

    if (!cmd || !pipe || !(node = malloc(sizeof(magic_node_t))))
        return FAILURE;
    init_magic(node);
    if (infos_in_magic(cmd, node) != SUCCESS)
        return FAILURE;
    put_node_in_list(node, pipe);
    pipe->size += 1;
    return SUCCESS;
}
