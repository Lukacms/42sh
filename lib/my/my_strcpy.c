/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** task01d06
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    if (!src)
        return NULL;
    for (int i = 0; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    return dest;
}
