/*
** EPITECH PROJECT, 2021
** my_str_isupper.c
** File description:
** task15d06
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    if (my_strlen(str) <= 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 'A' && str[i] > 'Z')
            return 0;
    }
    return 1;
}
