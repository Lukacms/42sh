/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command_alias
*/

#include <stdbool.h>
#include "mysh.h"
#include "my.h"

static int print_all_aliases(shell_t *shell)
{
    alias_node_t *tmp = shell->aliases.head;

    if (!tmp)
        return ERROR_BUILTIN;
    for (u_int i = 0; i < shell->aliases.size; i += 1) {
        my_printf("%s\t", tmp->name);
        print_alias_value(tmp->value, true);
        my_printf("\n");
        tmp = tmp->next;
    }
    return SUCCESS;
}

static int print_specific_alias(char *name, shell_t *shell)
{
    alias_node_t *node = find_alias_by_name(name, shell);

    if (!node)
        return ERROR_BUILTIN;
    print_alias_value(node->value, false);
    my_printf("\n");
    return SUCCESS;
}

static int alias_handle(char const *name, char * const value[], shell_t *shell)
{
    alias_node_t *node = find_alias_by_name(name, shell);

    if (!node)
        return add_alias_node(name, value, shell);
    return replace_alias(node, value);
}

int cmd_handler_alias(char **array, shell_t *shell)
{
    int i = 0;

    if (!array || !shell)
        return FAILURE;
    for (; array[i]; i++);
    if (i == 1)
        return print_all_aliases(shell);
    else if (i == 2)
        return print_specific_alias(array[1], shell);
    return alias_handle(array[1], array + 2, shell);
}
