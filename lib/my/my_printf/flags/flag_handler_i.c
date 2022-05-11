/*
** EPITECH PROJECT, 2021
** flag_handler_i.c
** File description:
** flag_handler_i
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_i(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}
