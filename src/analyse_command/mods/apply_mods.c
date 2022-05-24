/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** apply_mods
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int cmp_arrays(char **src, char **cmp)
{
    for (int i = 0; src[i] && cmp[i]; i++)
        if (my_strcmp(src[i], cmp[i]))
            return FAILURE;
    return SUCCESS;
}

char **apply_mods(char **og, shell_t *shell)
{
    char **new = NULL;
    char **dest = NULL;

    if (!og || !shell)
        return og;
    if ((new = analyse_aliases(og[0], shell)))
        dest = concate_arrays(new, og + 1);
    new = NULL;
    while (dest && (new = analyse_aliases(dest[0], shell)) &&
        cmp_arrays(new, dest))
        dest = concate_arrays(new, dest + 1);
    if (!dest)
        return og;
    return dest;
}
