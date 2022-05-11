/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** create_path_list
*/

#include <stdlib.h>
#include "mysh.h"

static int count_words(char const *str)
{
    int words = 0;

    if (str[0] != ':')
        words += 1;
    for (int i = 1; str[i] != '\0'; i += 1)
        if (str[i] != ':' && str[i - 1] == ':')
            words += 1;
    return words;
}

int create_path_list(shell_t *shell)
{
    env_node_t *node = find_variable_by_name(shell, "PATH");
    char *str = ((node) ? node->var_value : NULL);
    int words = 0;
    int j = 0;

    if (!node)
        return FAILURE;
    words = count_words(str);
    for (int i = 0; i < words; i++) {
        add_path_node(shell, str + j);
        for (; str[j] != ':' && str[j] != '\0'; j += 1);
        j += 1;
    }
    return SUCCESS;
}
