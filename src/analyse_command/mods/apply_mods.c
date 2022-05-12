/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** apply_mods
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char **apply_mods(char **og, shell_t *shell)
{
    char **new = NULL;
    char **dest = NULL;

    if (!og || !shell)
        return og;
    if ((new = analyse_aliases(og[0], shell)))
        dest = concate_arrays(new, og + 1);
    if (!dest)
        return og;
    return dest;
}
