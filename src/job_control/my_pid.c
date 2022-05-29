/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_pid
*/

#include <sys/types.h>

pid_t *get_mypid(void)
{
    static pid_t mypid = 0;

    return &mypid;
}

void set_mypid(pid_t value)
{
    pid_t *mypid = get_mypid();

    *mypid = value;
}
