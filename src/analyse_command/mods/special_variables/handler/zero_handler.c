/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** zero_handler
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char *zero_handler(shell_t *shell, char *line)
{
    char *new = NULL;

    if (!shell || !line)
        return NULL;
    if (!(new = my_strdup(shell->special.current_script)))
        return line;
    free(line);
    return new;
}
