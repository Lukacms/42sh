/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** alias
*/

#ifndef ALIAS_H_
    #define ALIAS_H_

    #include "mysh/infos.h"

/*
* @brief add a node to alias linked list
*
* @param name
* @param value
* @param shell
* @return int
*/
int add_alias_node(char const *name, char * const value[], shell_t *shell);

/*
* @brief find alias node by its name
*
* @param name
* @param shell
* @return alias_node_t*
*/
alias_node_t *find_alias_by_name(char const *name, shell_t *shell);

/*
* @brief replace alias value
*
* @param node
* @param array
* @return int
*/
int replace_alias(alias_node_t *node, char * const array[]);

/*
* @brief print the value of an alias
*
* @param value
* @param possibly_more
* @return int
*/
int print_alias_value(char * const value[], bool possibly_more);

char **analyse_aliases(char *og, shell_t *shell);
int delete_specific_alias(char *name, shell_t *shell);
int delete_all_aliases(shell_t *shell);

#endif /* !ALIAS_H_ */
