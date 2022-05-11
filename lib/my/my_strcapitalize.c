/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** task10d06
*/

#include <stdlib.h>
#include "my.h"

static int is_capital(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static int is_separator(char const c)
{
    if (c == ' ' || c == '\t' || c == '+' || c == '-' || c == '\n')
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    if (!str)
        return NULL;
    if (str[0] <= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != '\0'; i += 1) {
        if (str[i - 1] != ' ' && is_capital(str[i]) == 1)
            str[i] = str[i] + 32;
        else if (is_separator(str[i - 1]) == 1 && is_capital(str[i]) != 1)
            str[i] = str[i] - 32;
    }
    return (str);
}
