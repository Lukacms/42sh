/*
** EPITECH PROJECT, 2021
** flag_handler_upper_s.c
** File description:
** flag_handler_upper_s
*/

#include "my.h"
#include <stdarg.h>

static void check_nbr(char c)
{
    for (int i = 1; c * i <= 70; i *= 10)
        my_putchar('0');
    my_putnbr_base(c, "01234567");
}

static void my_printstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 32 && str[i] <= 126) {
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            check_nbr(str[i]);
        }
    }
}

void flag_handler_upper_s(va_list ap)
{
    my_printstr(va_arg(ap, char *));
}
