/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** task02d06
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!src)
        return NULL;
    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
