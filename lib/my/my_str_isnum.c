/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** task13d06
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    if (my_strlen(str) <= 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < '0' && str[i] > '9')
            return 0;
    }
    return 1;
}
