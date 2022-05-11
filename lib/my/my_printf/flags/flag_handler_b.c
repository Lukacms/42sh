/*
** EPITECH PROJECT, 2021
** flag_handler_b.c
** File description:
** flag_handler_b
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_b(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
