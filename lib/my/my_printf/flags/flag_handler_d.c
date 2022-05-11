/*
** EPITECH PROJECT, 2021
** flag_handler_d.c
** File description:
** flag_handler_d
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}
