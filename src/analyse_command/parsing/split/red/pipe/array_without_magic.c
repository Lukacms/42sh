/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** array_without_magic
*/

#include <stdlib.h>
#include "mysh/parse/parsing_infos.h"
#include "mysh/parse/parsing.h"
#include "my.h"

static char *str_without_quotes(char *og, int *i)
{
    char *dest = NULL;
    int size = my_strlen(og);
    int dup = 0;

    if (char_in_str(QUOTATION, og[0]))
        dup += 1;
    if (char_in_str(QUOTATION, og[size - 1]))
        size -= 2;
    dest = my_strndup(og + dup, size);
    *i += 1;
    return dest;
}

char **array_without_magic(char **og, pipe_node_t *pipe)
{
    char **clean = NULL;
    int len = 0;
    int y = 0;

    if (!og || !pipe)
        return NULL;
    for (unsigned int i = 0; og[i]; i += 1)
        if (og[i][0] != '`')
            len += 1;
    if (!(clean = malloc(sizeof(char *) * (len + 1))))
        return NULL;
    for (unsigned int i = 0; og[i]; i += 1) {
        if (og[i][0] == '`')
            add_magic(og[i], pipe);
        else
            clean[y] = str_without_quotes(og[i], &y);
    }
    clean[len] = NULL;
    return clean;
}
