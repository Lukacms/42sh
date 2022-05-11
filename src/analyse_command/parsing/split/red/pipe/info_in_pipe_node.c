/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** info_in_pipe_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static int is_pipe(char *delim)
{
    if (!delim || !(*delim))
        return -1;
    return my_strcmp("|", delim);
}

int info_in_pipe_node(pipe_node_t *node, char *cmd, char *delim)
{
    if (!node || !cmd)
        return FAILURE;
    if (is_pipe(delim) == SUCCESS)
        node->next_pipe = true;
    node->cmd = str_to_array_choice(cmd, SEPARATOR);
    return SUCCESS;
}
