/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** find_alias_by_name
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

alias_node_t *find_alias_by_name(char const *name, shell_t *shell)
{
    alias_node_t *tmp = NULL;

    if (!name || !shell || !(tmp = shell->aliases.head))
        return NULL;
    for (u_int i = 0; i < shell->aliases.size; i += 1) {
        if (my_strcmp(tmp->name, name) == SUCCESS)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
