/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** false_globals
*/

#include <unistd.h>

int *get_shell_fd(void)
{
    static int shellfd = STDERR_FILENO;

    return &shellfd;
}

void set_shellfd(int value)
{
    int *shellfd = get_shell_fd();

    *shellfd = value;
}
