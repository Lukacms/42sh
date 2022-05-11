/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** command_setenv
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else if (c >= '0' && c <= '9')
        return 1;
    return SUCCESS;
}

static int analyse_variable_given(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (is_alphanum(str[i]) == 0)
            return ERROR_BUILTIN;
    return SUCCESS;
}

int cmd_handler_setenv(char **array, shell_t *shell)
{
    int i = 0;
    const char *error = "Variable name must contain alphanumeric characters.";

    for (; array[i] != NULL; i++);
    if (i > 3) {
        my_printf("setenv: too many arguments\n");
        return ERROR_BUILTIN;
    }
    if (i == 1)
        return cmd_handler_env(NULL, shell);
    if (analyse_variable_given(array[1]) != SUCCESS) {
        my_printf("setenv: %s\n", error);
        return ERROR_BUILTIN;
    }
    return add_node_for_setenv(shell, array[1], array[2]);
}
