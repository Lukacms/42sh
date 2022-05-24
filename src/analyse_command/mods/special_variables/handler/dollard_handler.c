/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** dollard_handler
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char *dollard_handler(shell_t *shell, char *line)
{
    char *new = NULL;

    if (!shell || !line)
        return NULL;
    if (!(new = my_int_to_str(getpid())))
        return line;
    return new;
}
