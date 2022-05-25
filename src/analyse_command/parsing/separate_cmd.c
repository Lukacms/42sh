/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** separate_cmd
*/

#include <stdlib.h>
#include "my.h"

static int is_delim(char *cmd, char * const delim[])
{
    int size = 0;
    int cmp = 0;
    int cmd_size = my_strlen(cmd);

    for (int i = 0; delim[i]; i++) {
        size = my_strlen(delim[i]);
        if ((cmp = my_strncmp(cmd, delim[i], size)) == 0 || (
            size < cmd_size && cmp == cmd[size]))
            return size;
    }
    return -1;
}

static int count_len(char *cmd, char * const delim[])
{
    int size = 0;

    for (; cmd[size] && is_delim(cmd + size, delim) <= 0; size += 1);
    return size;
}

char *separate_cmd(char *cmd, char * const delim[], int *len)
{
    char *dest = NULL;

    if (!cmd || !delim || !(*delim))
        return NULL;
    (*len) = count_len(cmd, delim);
    if (!(dest = my_strndup(cmd, (*len))))
        return NULL;
    return dest;
}
