/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** task03d07
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int f = 0;

    if (nb > i)
        nb = i;
    for (; f < nb; f += 1)
        dest[i + f] = src[f];
    dest[i + f + 1] = '\0';
    return (dest);
}
