/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int main(int ac, char *const av[], char *const env[])
{
    if (ac != 1)
        return FAILURE;
    return launch(env, av);
}
