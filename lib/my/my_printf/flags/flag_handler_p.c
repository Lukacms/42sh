/*
** EPITECH PROJECT, 2021
** flag_handler_p.c
** File description:
** flag_handler_p
*/

#include "my.h"

void flag_handler_p(va_list ap)
{
    my_putaddr(va_arg(ap, unsigned long));
}
