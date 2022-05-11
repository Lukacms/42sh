/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** task05d06
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int size = my_strlen(to_find);
    int f = 0;
    int i = 0;

    if (size > my_strlen(str))
        return NULL;
    if (!to_find || to_find[0] == '\0')
        return (str);
    for (; str[i] != '\0' && to_find[f] != '\0'; i += 1) {
        if (str[i] == to_find[f]) {
            f++;
        } else if (f > 0)
            break;
    }
    if (f != size)
        return NULL;
    return str + i - f;
}
