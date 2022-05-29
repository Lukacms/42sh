/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** separate_cmd
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int is_delim(char *cmd, char * const delim[])
{
    int size = 0;
    int cmp = 0;

    for (int i = 0; delim[i]; i++) {
        size = my_strlen(delim[i]);
        if ((cmp = my_strncmp(cmd, delim[i], size)) == 0)
            return size;
    }
    return -1;
}

static int skip_quotes(char *cmd, char c)
{
    if (!cmd || !(*cmd)) {
        my_printf(MISMATCHED_PARSING, c);
        return -1;
    }
    for (unsigned int i = 1; cmd[i]; i += 1)
        if (cmd[i] == c)
            return i;
    my_printf(MISMATCHED_PARSING, c);
    return -1;
}

static int count_len(char *cmd, char * const delim[])
{
    int size = 0;
    int check = 0;

    for (; cmd[size] && is_delim(cmd + size, delim) <= 0; size += 1) {
        check = 0;
        if (char_in_str(QUOTATION, cmd[size]))
            check = skip_quotes(cmd + size, cmd[size]);
        if (check < 0)
            return -1;
        size += check;
    }
    return size;
}

char *separate_cmd(char *cmd, char * const delim[], int *len)
{
    char *dest = NULL;

    if (!cmd || !delim || !(*delim))
        return NULL;
    if (((*len) = count_len(cmd, delim)) < 0)
        return NULL;
    if (!(dest = my_strndup(cmd, (*len))))
        return NULL;
    return dest;
}
