/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** task08d06
*/

#include <stdlib.h>
#include "my.h"

char *my_strupcase(char *str)
{
    int i = my_strlen(str);

    if (i <= 0)
        return NULL;
    for (int f = 0; f < i; f++) {
        if ('a' <= str[f] && str[f] <= 'z')
            str[f] = str[f] - 32;
    }
    return str;
}
