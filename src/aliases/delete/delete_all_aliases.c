/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** delete_all_aliases
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

int delete_all_aliases(shell_t *shell)
{
    alias_node_t *anchor = NULL;
    alias_node_t *tmp = NULL;

    if (!shell || !(anchor = shell->aliases.head))
        return NOT_FOUND;
    for (u_int i = 0; i < shell->aliases.size; i++) {
        tmp = anchor;
        anchor = anchor->next;
        if (tmp->name)
            free(tmp->name);
        if (tmp->value)
            free_array((void **)tmp->value);
        free(tmp);
    }
    shell->aliases.head = NULL;
    shell->aliases.size = 0;
    return SUCCESS;
}
