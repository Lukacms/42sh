/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** info_red_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static char * const separate[] = {"|", NULL};

static const next_type_handler_t handler[] = {
    {.red = ">", .type = RIGHT_REDIRECT},
    {.red = ">>", .type = DOUBLE_RIGHT},
    {.red = "<", .type = LEFT_REDIRECT},
    {.red = "<<", .type = DOUBLE_LEFT},
    {.red = NULL, .type = R_NOTHING}
};

static redirect_type_t get_red(char *red)
{
    if (!red || !(*red))
        return R_NOTHING;
    for (unsigned int i = 0; handler[i].red; i++)
        if (my_strcmp(handler[i].red, red) == SUCCESS)
            return handler[i].type;
    return R_NOTHING;
}

static char *get_pipe(char *cmd)
{
    char *pipe = "|";
    int len = 1;
    int cmp = 0;

    if (!cmd || !(*cmd))
        return NULL;
    if ((cmp = my_strncmp(cmd, pipe, len)) == SUCCESS)
        return pipe;
    return NULL;
}

int info_red_node(red_node_t *node, char *cmd, char *delim)
{
    char *pipe = NULL;
    int index = 0;
    char *substring = NULL;
    int size = 0;

    if (!node)
        return FAILURE;
    size = my_strlen(cmd);
    for (int i = 0; (substring = separate_cmd(cmd + index, separate, &i))
        && index < size;) {
        index += i;
        pipe = get_pipe(cmd + index);
        add_pipe_node(node, substring, pipe);
        free(substring);
        index += my_strlen(pipe);
    }
    node->next_red = get_red(delim);
    return SUCCESS;
}
