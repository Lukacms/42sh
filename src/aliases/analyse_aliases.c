/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** analyse_aliases
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char **analyse_aliases(char *og, shell_t *shell)
{
    char **new = NULL;
    alias_node_t *node = NULL;

    if (!og || !shell)
        return NULL;
    if (!(node = find_alias_by_name(og, shell)))
        return NULL;
    if (!(new = node->value))
        return NULL;
    return new;
}
