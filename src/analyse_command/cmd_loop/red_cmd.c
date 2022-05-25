/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** red_cmd
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include "mysh/infos.h"
#include "mysh.h"
#include "my.h"

static const redirect_handler_binder_t redirect[] = {
    {.type = DOUBLE_LEFT, .handler = &double_left_redirect},
    {.type = DOUBLE_RIGHT, .handler = &double_right_redirect},
    {.type = LEFT_REDIRECT, .handler = &left_redirect},
    {.type = RIGHT_REDIRECT, .handler = &right_redirect},
    {0}
};

static int set_redirections(split_node_t *split, red_node_t *node,
shell_t *shell)
{
    int status = 0;

    for (unsigned int i = 0; redirect[i].handler; i++)
        if (redirect[i].type == node->prev_red) {
            status = redirect[i].handler(node, split, shell);
            break;
        }
    return status;
}

static void reset_in_out(shell_t *shell)
{
    shell->is_input = 0;
    shell->is_output = 0;
    shell->redirect = false;
}

int red_cmd_loop(split_node_t *split, shell_t *shell)
{
    red_node_t *node = NULL;
    int status = 0;

    if (!split || !shell || !split->head)
        return status;
    node = split->head->prev;
    if (split->size == 1 && check_unique_errors(node))
        return ERROR_REDIRECT;
    for (unsigned int i = 0; i < split->size; i++) {
        status |= set_redirections(split, node, shell);
        node = node->prev;
    }
    if (status != SUCCESS)
        return ERROR_REDIRECT;
    node = split->head;
    status = pipe_cmd_loop(node, shell);
    reset_in_out(shell);
    return status;
}
