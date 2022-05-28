/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** delete_handler
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

int delete_handler(shell_t *shell, char **line, int n)
{
    if (!shell)
        return NOT_FOUND;
    if (n <= 0)
        return SUCCESS;
    write(STDOUT_FILENO, "\b", 1);
    n -= 1;
    *line = realloc(*line, n);
    return SUCCESS;
}
