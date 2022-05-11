/*
** EPITECH PROJECT, 2021
** flag_handler_c.c
** File description:
** flag_handler_c
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
}
