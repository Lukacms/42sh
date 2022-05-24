/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** getnextline
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

ssize_t getshellline(shell_t *shell, char **ptr, size_t *n, FILE *stream)
{
    ssize_t len = 0;
    int i = 0;

    if (!ptr || !stream)
        return EOF;
    *n = 0;
    while ((i = getc(stream)) != END && i != EOF) {
        if (analyse_char(i, shell) == SUCCESS)
            continue;
        *n += 1;
        if (!((*ptr) = realloc((*ptr), (*n))))
            return FAILURE;
        ptr[0][*n] = i;
    }
    if (i == EOF)
        return EOF;
    len = my_strlen((*ptr));
    return len;
}
