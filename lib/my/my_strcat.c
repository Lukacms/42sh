/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task02d07
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *src, char const *add)
{
    int dest_len = my_strlen(src);
    int len = dest_len + my_strlen(add);
    char *dest = malloc(sizeof(char) * (len + 1));

    if (!dest || !add)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    for (int i = 0; add[i] != '\0'; i += 1)
        dest[i + dest_len] = add[i];
    dest[len] = '\0';
    return dest;
}
