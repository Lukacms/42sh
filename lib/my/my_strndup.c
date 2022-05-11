/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char *const src, int n)
{
    char *dest = NULL;
    int src_size = my_strlen(src);

    if (!src)
        return NULL;
    if (n > src_size)
        n = src_size;
    dest = malloc(sizeof(char) * (n + 1));
    if (!dest)
        return NULL;
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}
