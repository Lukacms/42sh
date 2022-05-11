/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** command_env
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int cmd_handler_env(char __attribute__((unused)) **array, shell_t *shell)
{
    env_node_t *tmp = NULL;

    if (shell == NULL || !shell->env.head)
        return ERROR_BUILTIN;
    tmp = shell->env.head;
    for (unsigned int i = 0; i < shell->env.size; i++) {
        my_printf("%s=%s\n", tmp->var_name,
                    tmp->var_value ? tmp->var_value : "");
        tmp = tmp->next;
    }
    return SUCCESS;
}
