/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** add_split_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static void init_node(split_node_t *node)
{
    node->head = NULL;
    node->size = 0;
    node->next_split = NOTHING;
    node->prev_split = NOTHING;
    node->next = node;
    node->prev = node;
}

static void put_node_in_list(shell_t *shell, split_node_t *node)
{
    if (!shell->cmd.head)
        shell->cmd.head = node;
    else {
        node->prev = shell->cmd.head->prev;
        node->next = shell->cmd.head;
        shell->cmd.head->prev->next = node;
        shell->cmd.head->prev = node;
    }
}

int add_split_node(shell_t *shell, char *cmd, char *delim)
{
    split_node_t *node = NULL;

    if (!shell || !(node = malloc(sizeof(split_node_t))))
        return FAILURE;
    init_node(node);
    if (info_split_node(node, cmd, delim) != SUCCESS)
        return FAILURE;
    if (shell->cmd.size > 0)
        node->prev_split = shell->cmd.head->prev->next_split;
    put_node_in_list(shell, node);
    shell->cmd.size += 1;
    return SUCCESS;
}
