/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** command_exit
*/

#include <stdbool.h>
#include "my.h"
#include "mysh.h"

int cmd_handler_exit(char __attribute__((unused))**array, shell_t *shell)
{
    if (!shell)
        return ERROR_BUILTIN;
    shell->finished = true;
    return SUCCESS;
}
