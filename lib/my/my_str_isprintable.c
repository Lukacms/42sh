/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** task16d06
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    if (my_strlen(str) <= 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] <= 31 && str[i] >= 127)
            return 0;
    }
    return 1;
}
