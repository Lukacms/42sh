/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** launch
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "mysh.h"

static void shell_loop(shell_t *shell)
{
    char *command = NULL;
    ssize_t size = 0;
    size_t count = 0;
    int status = 0;

    while (shell->finished != true && size != -1) {
        display_prompt(status, shell);
        size = getline(&command, &count, stdin);
        if (size != -1 && command[0] != '\n') {
            command[size - 1] = '\0';
            status = get_commands(shell, command);
        }
    }
    my_printf("exit\n");
    free(command);
}

int launch(char *const env[])
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (!shell || !env || !isatty(STDOUT_FILENO))
        return FAILURE;
    create_shell(shell, env);
    shell_loop(shell);
    free_list(shell);
    free(shell);
    return SUCCESS;
}
