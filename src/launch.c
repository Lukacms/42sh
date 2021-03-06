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
        size = getshellline(shell, &command, &count, stdin);
        if (size != -1 && command[0] != '\n') {
            command[size - 1] = '\0';
            status = get_commands(shell, command);
        }
        count = 0;
        free(command);
        command = NULL;
    }
    my_printf("exit\n");
    if (command)
        free(command);
}

int launch(char *const env[], char * const argv[])
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (!shell || !env || !argv)
        return FAILURE;
    create_shell(shell, env, argv);
    shell_loop(shell);
    free_list(shell);
    free(shell);
    return SUCCESS;
}
