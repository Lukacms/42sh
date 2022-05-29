/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** key_up_handler
*/

#include "mysh.h"

int key_up_handler(shell_t *shell, char __attribute__((unused))**line,
int __attribute__((unused))*n)
{
    if (!shell)
        return NOT_FOUND;
    return SUCCESS;
}
