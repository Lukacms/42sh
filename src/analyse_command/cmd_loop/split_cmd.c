/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** split_cmd
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static int exec_split(shell_t *shell, split_node_t *node, int status)
{
    if (node->prev_split == NOTHING || node->prev_split == SEMICOLON)
        return red_cmd_loop(node, shell);
    if (node->prev_split == DOUBLE_AMPERSAND && status == 0)
        return red_cmd_loop(node, shell);
    if (node->prev_split == DOUBLE_VBAR && status != 0)
        return red_cmd_loop(node, shell);
    return status;
}

int split_cmd_loop(shell_t *shell)
{
    split_node_t *node = NULL;
    int status = 0;

    if (!shell || !shell->cmd.head)
        return status;
    node = shell->cmd.head;
    for (unsigned int i = 0; i < shell->cmd.size; i++) {
        status = exec_split(shell, node, status);
        node = node->next;
    }
    return status;
}
