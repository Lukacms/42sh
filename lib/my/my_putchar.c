/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** lib
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
