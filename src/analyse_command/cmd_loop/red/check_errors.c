/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** check_errors
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int check_errors_left(red_node_t *node, red_node_t *concate, shell_t *shell)
{
    red_node_t *prev = node->prev;

    if ((prev->next_red != DOUBLE_LEFT && prev->next_red != LEFT_REDIRECT) ||
        !prev->head || !prev->head->cmd || !prev->head->cmd[0]) {
        my_printf("Invalid null command.\n");
        return FAILURE;
    }
    if ((concate->size > 1 && node->size > 1) ||
        shell->is_input != 0) {
        my_printf("Ambiguous input redirect.\n");
        return FAILURE;
    }
    if (!node->head || !node->head->cmd || !node->head->cmd[0]) {
        my_printf("Missing name for redirect.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int check_errors_right(red_node_t *node, shell_t *shell)
{
    red_node_t *prev = node->prev;

    if ((prev->next_red != DOUBLE_RIGHT && prev->next_red != RIGHT_REDIRECT) ||
        !prev->head || !prev->head->cmd || !prev->head->cmd[0]) {
        my_printf("Invalid null command.\n");
        return FAILURE;
    }
    if (node->size > 1 || shell->is_output != 0) {
        my_printf("Ambiguous output redirect.\n");
        return FAILURE;
    }
    if (!node->head || !node->head->cmd || !node->head->cmd[0]) {
        my_printf("Missing name for redirect.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int check_unique_errors(red_node_t *node)
{
    if (node->prev_red != R_NOTHING) {
        my_printf("Invalid null command.\n");
        return ERROR_BUILTIN;
    } else if (node->next_red != R_NOTHING) {
        my_printf("Missing name for redirect.\n");
        return ERROR_BUILTIN;
    }
    return SUCCESS;
}
