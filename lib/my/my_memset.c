/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** my_memset
*/

#include <sys/types.h>
#include <stdlib.h>

void my_memset(char *ptr, u_int x, char c)
{
    if (!ptr)
        return;
    for (u_int i = 0; i < x; i++)
        ptr[i] = c;
}
