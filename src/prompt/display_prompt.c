/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** display_prompt
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"
#include "my.h"

void display_prompt(int status, shell_t *shell)
{
    char *file = NULL;
    int current_dir = 0;
    env_node_t *node = find_variable_by_name(shell, "USER");

    file = getcwd(file, 0);
    current_dir = my_strlen(file) - 1;
    my_printf("%s [%d] ", (node ? node->var_value : NULL), status);
    for (; file[current_dir] != '/' && current_dir > 0; current_dir--);
    my_printf("%s $ ", (file[current_dir + 1] != '\0'
                ? file + current_dir + 1 : file + current_dir));
    free(file);
}
