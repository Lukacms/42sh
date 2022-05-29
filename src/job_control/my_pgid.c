/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_pgid
*/

#include <sys/types.h>

pid_t *get_mypgid(void)
{
    static pid_t mypgid = 0;

    return &mypgid;
}

void set_mypgid(pid_t value)
{
    pid_t *mypgid = get_mypgid();

    *mypgid = value;
}
