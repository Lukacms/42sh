/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** concat_arrays
*/

#include <stdlib.h>
#include "my.h"

char **concate_arrays(char **src, char **add)
{
    char **dest = NULL;
    int i = 0;
    int x = 0;

    for (; src[i]; i++);
    for (int j = 0; add[j]; j++)
        i++;
    if (!(dest = malloc(sizeof(char *) * (i + 1))))
        return NULL;
    for (; src[x]; x++)
        dest[x] = my_strdup(src[x]);
    for (int j = 0; add[j]; j++)
        dest[x + j] = my_strdup(add[j]);
    dest[i] = NULL;
    return dest;
}
