/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parse_args
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

static char * const splits[] = {";", "&&", "||", "&", NULL};

static char *get_split(char *cmd)
{
    if (!cmd)
        return NULL;
    for (int i = 0; splits[i]; i += 1)
        if (my_strncmp(cmd, splits[i], my_strlen(splits[i])) == SUCCESS)
            return splits[i];
    return NULL;
}

int parse_cmd(char *cmd, shell_t *shell)
{
    char *substring = NULL;
    int index = 0;
    char *delim = NULL;
    int size = 0;

    if (!cmd || !shell)
        return FAILURE;
    size = my_strlen(cmd);
    for (int i = 0; (substring = separate_cmd(cmd + index, splits, &i))
        && index < size;) {
        index += i;
        delim = get_split(cmd + index);
        add_split_node(shell, substring, delim);
        free(substring);
        index += my_strlen(delim);
    }
    return SUCCESS;
}
