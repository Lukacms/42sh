/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "mysh/infos.h"

/*
* @brief Create a env list object
*
* @param env
* @param env_list
* @return int - SUCCESS | FAILURE
*/
int create_env_list(char *const env[], shell_t *shell);

/*
* @brief add a node for env linked list
*
* @param list
* @param env_line
* @return int - SUCCESS | FAILURE
*/
int add_node(shell_t *shell, char *const env_line);

/*
* @brief free env_linked list
*
* @param list
* @return None
*/
void free_list(shell_t *shell);

/*
* @brief find a variable of env by its name
*
* @param list
* @param name
* @return env_node_t*
*/
env_node_t *find_variable_by_name(shell_t *shell, char *name);

/*
* @brief replace a value of an env variable
*
* @param list
* @param name
* @param value
* @return int - SUCCESS | FAILURE
*/
int replace_variable_value(shell_t *shell, char *name, char *value);

/*
* @brief add a node for cmd setenv
*
* @param list
* @param name
* @param value
* @return int - SUCCESS | FAILURE
*/
int add_node_for_setenv(shell_t *shell, char *name, char *value);

/*
* @brief free a specific node
*
* @param list
* @param to_find
* @return None - no error to handle
*/
void free_specific_node(shell_t *shell, char *to_find);

/*
* @brief linked list for paths (executing a command)
*
* @param list
* @return int - SUCCESS | FAILURE
*/
int create_path_list(shell_t *shell);

/*
* @brief add a node
*
* @param shell
* @param one_of_paths
* @return int - SUCCESS | FAILURE
*/
int add_path_node(shell_t *shell, char *one_of_paths);

/*
* @brief free nodes for path
*
* @param shell
* @return None - no error to handle
*/
void free_paths_nodes(shell_t *shell);

#endif /* !LIST_H_ */
