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

char **array_without_magic(char **og, pipe_node_t *pipe)
{
    char **clean = NULL;
    int len = 0;

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
            clean[i] = my_strdup(og[i]);
    }
    clean[len] = NULL;
    return clean;
}
