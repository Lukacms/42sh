/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int main(int ac, char __attribute__((unused))*const av[], char *const env[])
{
    if (ac != 1)
        return FAILURE;
    int fileno = open("tests/minishell2/integration.txt", O_RDWR);
    dup2(fileno, STDIN_FILENO);
    return launch(env);
}
