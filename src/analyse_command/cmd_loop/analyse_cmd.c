/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** get_commands
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static const command_handler_binder_t command_handler[] = {
    {.existing_command = "cd", .handler = &cmd_handler_cd},
    {.existing_command = "env", .handler = &cmd_handler_env},
    {.existing_command = "exit", .handler = &cmd_handler_exit},
    {.existing_command = "setenv", .handler = &cmd_handler_setenv},
    {.existing_command = "unsetenv", .handler = &cmd_handler_unsetenv},
    {.existing_command = "alias", .handler = &cmd_handler_alias},
    {.existing_command = "unalias", .handler = &cmd_handler_unalias},
    {.existing_command = "history", .handler = &cmd_handler_history},
    {0}
};

int analyse_cmd(char **cmd_array, shell_t *shell)
{
    int status = 0;

    if (!shell || !cmd_array || !cmd_array[0])
        return NO_COMMAND;
    cmd_array = apply_mods(cmd_array, shell);
    for (int i = 0; command_handler[i].handler != NULL; i++) {
        if (my_strcmp(cmd_array[0], command_handler[i].existing_command) == 0)
            return command_handler[i].handler(cmd_array, shell);
    }
    status = execute_command(shell, cmd_array);
    free_paths_nodes(shell);
    return status;
}
