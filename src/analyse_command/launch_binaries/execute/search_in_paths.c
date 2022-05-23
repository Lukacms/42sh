/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** search_in_paths
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int search_command_in_path(shell_t *shell, char **cmd, char *const env[])
{
    char *path = NULL;
    path_node_t *tmp = NULL;
    int status = 0;

    if (create_path_list(shell) != SUCCESS || !(tmp = shell->path.head))
        return UNKNOWN;
    for (unsigned int i = 0; i < shell->path.size; i++) {
        path = my_strcat(tmp->path, cmd[0]);
        if ((status = execute_binary(path, cmd, env, shell)) != UNKNOWN) {
            free(path);
            return status;
        }
        tmp = tmp->next;
        free(path);
        path = NULL;
    }
    return UNKNOWN;
}
