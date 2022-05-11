/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** command_unsetenv
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int cmd_handler_unsetenv(char **array, shell_t *shell)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    if (i < 2) {
        my_printf("unsetenv: too few arguments\n");
        return ERROR_BUILTIN;
    }
    if (my_strcmp(array[1], "*") == 0)
        free_list(shell);
    else
        for (int j = 1; j < i; j++)
            free_specific_node(shell, array[j]);
    return SUCCESS;
}
