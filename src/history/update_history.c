/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** update_history
*/

#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static int array_len(char **array)
{
    int i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}

int update_history(char *cmd, shell_t *shell)
{
    int size = 0;
    int array_size = array_len(shell->history.history);

    if (!cmd || !shell)
        return FAILURE;
    size = my_strlen(cmd);
    array_size += 1;
    shell->history.history =
        my_reallocarray(shell->history.history, array_size, size);
    shell->history.history[array_size - 1] = my_strdup(cmd);
    return SUCCESS;
}
