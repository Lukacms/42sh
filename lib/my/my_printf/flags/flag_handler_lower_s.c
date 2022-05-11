/*
** EPITECH PROJECT, 2021
** flag_handler_s.c
** File description:
** flag_handler_s
*/

#include "my.h"
#include <stdarg.h>

void flag_handler_lower_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}
