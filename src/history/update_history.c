/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** update_history
*/

#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int update_history(char *cmd, shell_t *shell)
{
    u_int i = 0;
    int size = 0;

    if (!cmd || !shell)
        return FAILURE;
    size = my_strlen(cmd);
    if (shell->history.history)
        for (; shell->history.history[i]; i++);
    i += 1;
    shell->history.history = my_reallocarray(shell->history.history, i, size);
    my_strcpy(shell->history.history[i - 1], cmd);
    return SUCCESS;
}
