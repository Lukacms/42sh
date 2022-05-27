/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** my_reallocarray
*/

#include <sys/types.h>
#include <stdlib.h>
#include "my.h"

char **my_reallocarray(char **ptr, unsigned int y, unsigned int x)
{
    char **new_ptr = NULL;
    unsigned int i = 0;

    new_ptr = malloc(sizeof(char *) * (y + 1));
    if (!new_ptr)
        return NULL;
    for (; ptr && ptr[i]; i++)
        new_ptr[i] = my_strdup(ptr[i]);
    new_ptr[y] = NULL;
    free_array((void **)ptr);
    return new_ptr;
}
