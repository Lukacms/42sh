/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** execute_command
*/

#include <stdio.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int is_fullpath(char const *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '/')
            return 1;
    }
    return SUCCESS;
}

int execute_command(shell_t *shell, char **cmd)
{
    char **env = env_to_array(shell);
    int status = 0;

    if (!cmd)
        return SUCCESS;
    if (is_fullpath(cmd[0]) == 1) {
        if ((status = execute_binary(cmd[0], cmd, env, shell)) == UNKNOWN)
            my_printf("%s: command not found.\n", cmd[0]);
    } else if ((status = search_command_in_path(shell, cmd, env)) == UNKNOWN)
        my_printf("%s: command not found.\n", cmd[0]);
    free_array((void **)env);
    return status;
}
