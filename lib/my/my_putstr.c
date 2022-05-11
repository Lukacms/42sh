/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** displays the characters of a string one by one
*/

#include <stddef.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
