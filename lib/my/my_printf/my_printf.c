/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "my.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

static const pflag_handler_t flags_handlers[] = {
    {.flag = 'c', .handler = &flag_handler_c},
    {.flag = 's', .handler = &flag_handler_lower_s},
    {.flag = 'd', .handler = &flag_handler_d},
    {.flag = 'i', .handler = &flag_handler_i},
    {.flag = 'b', .handler = &flag_handler_b},
    {.flag = 'S', .handler = &flag_handler_upper_s},
    {.flag = 'o', .handler = &flag_handler_o},
    {.flag = 'u', .handler = &flag_handler_u},
    {.flag = 'x', .handler = &flag_handler_lower_x},
    {.flag = 'X', .handler = &flag_handler_upper_x},
    {.flag = 'p', .handler = &flag_handler_p},
    {.flag = '%', .handler = &flag_handler_percent},
    {.flag = '\0', .handler = NULL}
};

static int find_matching_flag_handler(char *str, va_list list)
{
    int c = 1;

    for (int i = 0; flags_handlers[i].handler != NULL; i += 1) {
        if (flags_handlers[i].flag == str[c]) {
            flags_handlers[i].handler(list);
            return c;
        }
    }
    return 0;
}

int my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '%')
            i += find_matching_flag_handler(str + i, list);
        else
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}
