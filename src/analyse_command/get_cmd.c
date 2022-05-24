/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** get_cmd
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int get_commands(shell_t *shell, char *cmd)
{
    int status = 0;

    if (!shell || !cmd)
        return SUCCESS;
    if (update_history(cmd, shell) != SUCCESS)
        return status;
    if (parse_cmd(cmd, shell) != SUCCESS)
        return status;
    status = split_cmd_loop(shell);
    free_split_node(shell);
    return status;
}
