/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** underscore_handler
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char *underscore_handler(shell_t *shell, char *line)
{
    char *new = NULL;
    int size = 0;

    if (!shell || !line)
        return NULL;
    if (!(shell->special.last))
        return line;
    for (; shell->special.last[size]; size += 1);
    if (size <= 0)
        return line;
    new = my_strdup(shell->special.last[size - 1]);
    return new;
}
