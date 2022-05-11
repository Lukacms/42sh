/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** my_reallocarray
*/

#include <sys/types.h>
#include <stdlib.h>
#include "my.h"

char **my_reallocarray(char **ptr, u_int y, u_int x)
{
    char **new_ptr = NULL;
    u_int i = 0;

    new_ptr = malloc(sizeof(char *) * (y + 1));
    if (!new_ptr)
        return NULL;
    for (i = 0; ptr && ptr[i]; i++)
        new_ptr[i] = my_strdup(ptr[i]);
    for (; i < y; i++) {
        if (!(new_ptr[i] = malloc(sizeof(char) * (x + 1))))
            return NULL;
        my_memset(new_ptr[i], x, '\0');
    }
    new_ptr[y] = NULL;
    free_array((void **)ptr);
    return new_ptr;
}
