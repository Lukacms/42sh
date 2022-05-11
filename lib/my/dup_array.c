/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** dup_array
*/

#include <stdlib.h>
#include "my.h"

char **dup_array(char * const origin[])
{
    char **dest = NULL;
    int i = 0;

    if (!origin)
        return NULL;
    for (; origin[i]; i++);
    if (!(dest = malloc(sizeof(char *) * (i + 1))))
        return NULL;
    for (int y = 0; y < i; y++) {
        if (!(dest[y] = my_strdup(origin[y])))
            return NULL;
    }
    dest[i] = NULL;
    return dest;
}
