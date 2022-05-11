/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** right_redirect
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int right_redirect(red_node_t *node, split_node_t *split, shell_t *shell)
{
    int status = 0;

    if (!node || !split || !shell)
        return status;
    if (check_errors_right(node, shell) != SUCCESS)
        return FAILURE;
    if ((shell->is_output = open(node->head->cmd[0], O_CREAT | O_TRUNC | O_RDWR,
        0666)) < 0)
        return FAILURE;
    node->prev->head->prev->cmd = concate_arrays(node->prev->head->prev->cmd,
                                                node->head->cmd + 1);
    return status;
}
