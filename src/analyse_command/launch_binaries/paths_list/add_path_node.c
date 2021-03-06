/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** add_path_node
*/

#include <string.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void init_node(path_node_t *node)
{
    node->path = NULL;
    node->prev = node;
    node->next = node;
}

static void put_path_in_node(path_node_t *node, char *path)
{
    int i = 0;

    for (; path[i] != ':' && path[i] != '\0'; i += 1);
    node->path = malloc(sizeof(char) * (i + 2));
    memset(node->path, '\0', sizeof(char) * (i + 1));
    node->path = my_strncpy(node->path, path, i);
    node->path[i] = '/';
    node->path[i + 1] = '\0';
}

static void put_node_in_list(shell_t *shell, path_node_t *node)
{
    if (!shell->path.head)
        shell->path.head = node;
    else {
        node->prev = shell->path.head->prev;
        node->next = shell->path.head;
        shell->path.head->prev->next = node;
        shell->path.head->prev = node;
    }
}

int add_path_node(shell_t *shell, char *one_of_paths)
{
    path_node_t *node = NULL;

    if (!shell || !one_of_paths)
        return FAILURE;
    if (!(node = malloc(sizeof(path_node_t))))
        return FAILURE;
    init_node(node);
    put_path_in_node(node, one_of_paths);
    put_node_in_list(shell, node);
    shell->path.size += 1;
    return SUCCESS;
}
