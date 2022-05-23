/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command_alias
*/

#include "mysh.h"
#include "my.h"

int cmd_handler_unalias(char **array, shell_t *shell)
{
    int i = 0;

    if (!array || !shell)
        return ERROR_BUILTIN;
    for (; array[i]; i++);
    if (i == 1) {
        my_printf("unalias: Too few arguments.\n");
        return ERROR_BUILTIN;
    } else if (i == 2 && my_strcmp(array[1], ALL) == SUCCESS)
        return delete_all_aliases(shell);
    for (i = 1; array[i]; i++)
        delete_specific_alias(array[i], shell);
    return SUCCESS;
}
