/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** inhibitor
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"
#include "my.h"

static char **inhibitor_loop(char **og, int i)
{
    ssize_t len = 0;
    size_t size = 0;
    char *cmd = NULL;

    og[i - 1][my_strlen(og[i - 1]) - 1] = '\0';
    while (len >= 0) {
        my_printf("? ");
        len = getline(&cmd, &size, stdin);
        cmd[len - 1] = '\0';
        i += 1;
        og = my_reallocarray(og, i);
        og[i - 1] = my_strdup(cmd);
        og[i] = NULL;
        if (len > 1 && cmd[len - 2] != '\\')
            break;
        og[i - 1][len - 2] = '\0';
    }
    return og;
}

char **inhibitor(char **og)
{
    int i = 0;

    if (!og)
        return NULL;
    i = array_len(og);
    if (og[i - 1][my_strlen(og[i - 1]) - 1] != '\\')
        return og;
    og = inhibitor_loop(og, i);
    return og;
}
