/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** my_memset
*/

#include <sys/types.h>
#include <stdlib.h>

void my_memset(char *ptr, unsigned int x, char c)
{
    if (!ptr)
        return;
    for (unsigned int i = 0; i < x; i++)
        ptr[i] = c;
}
