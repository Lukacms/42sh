/*
** EPITECH PROJECT, 2021
** flag_handler_lower_x.c
** File description:
** flag_handler_lower_x
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_lower_x(va_list ap)
{
    my_putnbr_base_unsign(va_arg(ap, unsigned int), "0123456789abcdef");
}
