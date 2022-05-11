/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** destroy_paths
*/

#include <stdlib.h>
#include "mysh.h"

void free_paths_nodes(shell_t *shell)
{
    path_node_t *tmp = shell->path.head;
    path_node_t *anchor = shell->path.head;

    if (!tmp)
        return;
    for (unsigned int i = 0; i < shell->path.size; i += 1) {
        anchor = anchor->next;
        free(tmp->path);
        free(tmp);
        tmp = anchor;
    }
    shell->path.head = NULL;
    shell->path.size = 0;
}
