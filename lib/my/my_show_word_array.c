/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** task03d08
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i += 1)
        my_printf("%s\n", tab[i]);
    return 0;
}
