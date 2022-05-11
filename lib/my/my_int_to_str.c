/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_int_to_str
*/

#include <stdlib.h>
#include <stddef.h>

char *my_int_to_str(int nb)
{
    char *dest = NULL;
    int i = 1;
    int j = 0;

    for (; (nb / i) > 9; i = i * 10)
        j += 1;
    dest = malloc(sizeof(char) * (j + 1));
    j = 0;
    for (; i != 0; i /= 10) {
        dest[j] = (nb / i) + '0';
        nb = nb % i;
        j += 1;
    }
    dest[j] = '\0';
    return dest;
}
