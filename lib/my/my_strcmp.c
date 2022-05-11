/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** task06d06
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return -1;
    for (; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return s1[i] - s2[i];
}
