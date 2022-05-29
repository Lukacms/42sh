/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** fgpid
*/

#include <sys/types.h>

pid_t *get_fgpid(void)
{
    static pid_t mypid = 0;

    return &mypid;
}

void set_fgpid(pid_t value)
{
    pid_t *fgpid = get_fgpid();

    *fgpid = value;
}
