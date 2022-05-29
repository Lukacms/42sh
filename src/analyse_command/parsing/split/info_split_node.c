/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** info_split_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static char * const redirect[] = {"<<", "<", ">>", ">", NULL};

static const next_type_handler_t handler[] = {
    {.red = ";", .split = SEMICOLON},
    {.red = "&&", .split = DOUBLE_AMPERSAND},
    {.red = "||", .split = DOUBLE_VBAR},
    {.red = NULL, .split = NOTHING}
};

static split_type_t get_split(char *split)
{
    if (!split || !(*split))
        return NOTHING;
    for (unsigned int i = 0; handler[i].red; i++)
        if (my_strcmp(handler[i].red, split) == SUCCESS)
            return handler[i].split;
    return NOTHING;
}

static char *get_red(char *cmd)
{
    int cmp = 0;
    int size = 0;

    if (!cmd || !(*cmd))
        return NULL;
    for (int i = 0; redirect[i]; i += 1) {
        size = my_strlen(redirect[i]);
        if ((cmp = my_strncmp(cmd, redirect[i], size)) == SUCCESS)
            return redirect[i];
    }
    return NULL;
}

int info_split_node(split_node_t *node, char *cmd, char *delim)
{
    char *red = NULL;
    int index = 0;
    char *substring = NULL;
    int size = 0;

    if (!node)
        return FAILURE;
    size = my_strlen(cmd);
    for (int i = 0; (substring = separate_cmd(cmd + index, redirect, &i))
        && index < size;) {
        index += i;
        red = get_red(cmd + index);
        add_redirect_node(node, substring, red);
        free(substring);
        index += my_strlen(red);
    }
    node->next_split = get_split(delim);
    return SUCCESS;
}
