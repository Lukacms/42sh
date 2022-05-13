/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** analyse_char
*/

#include <ncurses.h>
#include "mysh.h"

static const char_handler_t handler[] = {
    {.c = KEY_UP, .handler = NULL},
    {.c = KEY_DOWN, .handler = NULL},
    {.c = KEY_LEFT, .handler = NULL},
    {.c = KEY_RIGHT, .handler = NULL},
    {.c = ctrl('l'), .handler = NULL},
    {0}
};

int analyse_char(int c, shell_t *shell)
{
    return FAILURE;
}
