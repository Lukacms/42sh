/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** free_split_node
*/

#include <stdlib.h>
#include <sys/types.h>
#include "mysh/parse/parsing.h"
#include "mysh.h"
#include "my.h"

void free_split_node(shell_t *shell)
{
    split_node_t *anchor = NULL;
    split_node_t *tmp = NULL;

    if (!shell || !shell->cmd.head)
        return;
    anchor = shell->cmd.head;
    tmp = shell->cmd.head;
    for (unsigned int i = 0; i < shell->cmd.size; i++) {
        anchor = anchor->next;
        free_red_list(tmp);
        free(tmp);
        tmp = anchor;
    }
    shell->cmd.head = NULL;
    shell->cmd.size = 0;
}
