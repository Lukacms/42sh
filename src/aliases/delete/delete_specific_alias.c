/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** delete_specific_alias
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int delete_specific_alias(char *name, shell_t *shell)
{
    alias_node_t *alias = NULL;

    if (!name || !shell || !(alias = find_alias_by_name(name, shell)))
        return FAILURE;
    shell->aliases.size -= 1;
    if (shell->aliases.size == 0)
        shell->aliases.head = NULL;
    else if (alias == shell->aliases.head)
        shell->aliases.head = shell->aliases.head->next;
    alias->prev->next = alias->next;
    alias->next->prev = alias->prev;
    if (alias->name)
        free(alias->name);
    if (alias->value)
        free_array((void **)alias->value);
    free(alias);
    return SUCCESS;
}
