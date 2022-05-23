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

    if (!shell || !(history = shell->history.history))
        return ERROR_BUILTIN;
    for (u_int i = 0; history[i]; i++) {
        my_printf("%d %s\n", i, history[i]);
    }
    return SUCCESS;
}
