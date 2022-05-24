/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command_history
*/

#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int cmd_handler_history(char __attribute__((unused))**array, shell_t *shell)
{
    char **history = NULL;
    int incrementer = 1;
    int i = 0;

    if (!shell || !(history = shell->history.history))
        return ERROR_BUILTIN;
    if (shell->history.sort) {
        i = array_len(history) - 1;
        incrementer = -1;
    }
    for (; i >= 0 && i < array_len(shell->history.history); i += incrementer) {
        if (!(shell->history.without_number))
            my_printf("%d ", i);
        my_printf("%s\n", history[i]);
    }
    shell->history.without_number = 0;
    shell->history.sort = 0;
    return SUCCESS;
}
