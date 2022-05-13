/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** init_history
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int init_history(history_t *history)
{
    if (!history)
        return FAILURE;
    if ((history->fileno = open(HISTORY_FILE, HISTORY_FLAGS, FILE_MODE)) < 0)
        return INVALID_FILE;
    return FILE_INIT_CORRECT;
}
