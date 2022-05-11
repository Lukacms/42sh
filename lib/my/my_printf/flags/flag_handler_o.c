/*
** EPITECH PROJECT, 2021
** flag_handler_o.c
** File description:
** flag_handler_o
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_o(va_list ap)
{
    my_putnbr_base_unsign(va_arg(ap, unsigned int), "01234567");
}
