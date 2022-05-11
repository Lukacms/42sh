/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** left_redirect
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int left_redirect(red_node_t *node, split_node_t *split, shell_t *shell)
{
    int status = 0;
    red_node_t *concate = NULL;

    if (!node || !split || !shell)
        return status;
    concate = split->head;
    if (check_errors_left(node, concate, shell) != SUCCESS)
        return FAILURE;
    if ((shell->is_input = open(node->head->cmd[0], O_RDONLY)) < 0)
        return FAILURE;
    node->prev->head->cmd = concate_arrays(node->prev->head->cmd,
                            node->head->cmd + 1);
    return status;
}
