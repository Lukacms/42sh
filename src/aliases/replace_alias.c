/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** replace_alias
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int replace_alias(alias_node_t *node, char * const array[])
{
    if (!node || !array)
        return FAILURE;
    free_array((void **)node->value);
    node->value = dup_array(array);
    return SUCCESS;
}
