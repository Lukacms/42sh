/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** special_variables
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static const variable_handling_t variable[] = {
    {.variable = "$?", .handler = &interogation_handler},
    {.variable = "$$", .handler = &dollard_handler},
    {.variable = "$_", .handler = &underscore_handler},
    {.variable = "$0", .handler = &zero_handler},
    {.variable = "$#", .handler = &hashtag_handler},
    {.variable = "$!", .handler = &exclamation_handler},
    {0}
};

static char *get_special_handling(char *line, shell_t *shell)
{
    for (unsigned int i = 0; variable[i].handler; i += 1) {
        if (my_strcmp(line, variable[i].variable) == SUCCESS)
            return variable[i].handler(shell, line);
    }
    return line;
}

static char *get_env_handling(char *line, shell_t *shell)
{
    env_node_t *node = shell->env.head;

    if (!node || line[0] != '$')
        return line;
    for (unsigned int i = 0; i < shell->env.size; i += 1) {
        if (my_strcmp(line + 1, node->var_name) == SUCCESS) {
            free(line);
            line = my_strdup(node->var_value);
            return line;
        }
        node = node->next;
    }
    return line;
}

char **special_variables(char **og, shell_t *shell)
{
    if (!og || !(*og) || !shell)
        return NULL;
    for (unsigned int i = 0; og[i]; i += 1) {
        og[i] = get_special_handling(og[i], shell);
        og[i] = get_env_handling(og[i], shell);
    }
    return og;
}
