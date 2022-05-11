/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** task01d08
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int f = 0;
    char *dest = NULL;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[f] != '\0'; f += 1)
        dest[f] = src[f];
    dest[f] = '\0';
    return dest;
}
