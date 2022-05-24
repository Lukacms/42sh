/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** special_variables
*/

#include <stdlib.h>
#include "mysh.h"

static const variable_handling_t variable[] = {
    {.variable = "$?", .handler = NULL},
    {.variable = "$$", .handler = NULL},
    {.variable = "$_", .handler = NULL},
    {.variable = "$0", .handler = NULL},
    {.variable = "$#", .handler = NULL},
    {.variable = "$!", .handler = NULL},
    {0}
};

char **special_variables(char **og, shell_t *shell)
{
    char **dest = og;

    if (!og || !(*og) || !shell)
        return NULL;
    return dest;
}
