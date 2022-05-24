/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** interogation_handler
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char *interogation_handler(shell_t *shell, char *line)
{
    char *new = NULL;

    if (!shell || !line)
        return NULL;
    if (!(new = my_int_to_str(shell->special.status)))
        return line;
    free(line);
    return new;
}
