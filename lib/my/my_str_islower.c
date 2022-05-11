/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** task14d06
*/

#include "my.h"

int my_str_islower(char const *str)
{
    if (my_strlen(str) <= 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
