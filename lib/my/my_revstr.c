/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** task03d06
*/

#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char k = '\0';

    if (!str || i < 0)
        return NULL;
    for (; i > j; i -= 1) {
        k = str[i];
        str[i] = str[j];
        str[j] = k;
        j++;
    }
    return str;
}
