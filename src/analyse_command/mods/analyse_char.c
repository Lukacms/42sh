/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** analyse_char
*/

#include <sys/types.h>
#include <curses.h>
#include "mysh.h"

static const char_handler_t handler[] = {
    {.c = KEY_UP, .handler = key_up_handler},
    {.c = KEY_DOWN, .handler = key_down_handler},
    {.c = KEY_LEFT, .handler = key_left_handler},
    {.c = KEY_RIGHT, .handler = key_right_handler},
    {.c = '\f', .handler = ctrl_l_handler},
    {0}
};

int analyse_char(int c, shell_t *shell)
{
    if (!c || !shell)
        return FAILURE;
    for (u_int i = 0; handler[i].handler; i += 1) {
        if (handler[i].c == c)
            return handler[i].handler(shell);
    }
    return FAILURE;
}
