/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** env_to_array
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static char *dup_info_in_string(env_node_t *node)
{
    char *name = NULL;
    int name_size = my_strlen(node->var_name);
    int value_size = my_strlen(node->var_value);
    int size = name_size + value_size;

    name = malloc(sizeof(char) * (size + 2));
    if (!name)
        return NULL;
    for (int i = 0; i < name_size; i++)
        name[i] = node->var_name[i];
    name[name_size] = '=';
    for (int j = 0; j < value_size; j++)
        name[name_size + j + 1] = node->var_value[j];
    name[size + 1] = '\0';
    return name;
}

char **env_to_array(shell_t *shell)
{
    char **env = NULL;
    env_node_t *node = NULL;

    if (!shell || !shell->env.head)
        return NULL;
    node = shell->env.head;
    env = malloc(sizeof(char *) * (shell->env.size + 1));
    for (unsigned int i = 0; i < shell->env.size; i++) {
        env[i] = dup_info_in_string(node);
        if (!env[i])
            return NULL;
        node = node->next;
    }
    env[shell->env.size] = NULL;
    return env;
}
