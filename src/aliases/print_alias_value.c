/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** print_alias_value
*/

#include <stdbool.h>
#include "mysh.h"
#include "my.h"

int print_alias_value(char * const value[], bool possibly_more)
{
    int i = 0;

    if (!value)
        return FAILURE;
    for (; value[i]; i++);
    if (possibly_more && i > 1)
        my_printf("(");
    for (int j = 0; value[j]; j++) {
        my_printf("%s", value[j]);
        if (j < i - 1)
            my_printf(" ");
    }
    if (possibly_more && i > 1)
        my_printf(")");
    return SUCCESS;
}
