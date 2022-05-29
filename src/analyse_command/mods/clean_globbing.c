/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** clean_globbing
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int check_double(char *str, char **tab, int index, int mods)
{
    if (!mods)
        return 0;
    for (int i = 0; tab[i] && i < index; ++i) {
        if (my_strcmp(str, tab[i]) == 0)
            return 1;
    }
    return 0;
}

char **my_clean_array(char **tab, int mods)
{
    int len_tab = 0;
    int ind = 0;
    char **result = NULL;

    if (!tab)
        return NULL;
    for (int i = 0; tab[i]; i++) {
        if (!glob_inside(tab[i]) && !check_double(tab[i], tab, i, mods))
            len_tab++;
    }
    result = malloc(sizeof(char *) * (len_tab + 1));
    for (int i = 0; tab[i] != NULL && ind < len_tab; ++i) {
        if (!glob_inside(tab[i]) && !check_double(tab[i], result, ind, mods)) {
            result[ind] = my_strdup(tab[i]);
            ind++;
        }
    }
    result[len_tab] = NULL;
    return result;
}
