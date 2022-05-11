/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "mysh/infos.h"
    #include "mysh/parse/parsing_infos.h"

/*
* @brief parse command in 3 linked lists
*
* @param cmd
* @param shell
* @return int
*/
int parse_cmd(char *cmd, shell_t *shell);

/*
* @brief separate the command sent into a substring
*
* @param cmd
* @param delim
* @param len - pointer that will give the len of the string to increment
* @return char* - new substring
*/
char *separate_cmd(char *cmd, char * const delim[], int *len);

/******************************************/
/*                   split                */
/******************************************/

/*
* @brief split arguments into nodes seperated by spliters
* -> ';', '&&', '||', '&'
*
* @param shell
* @param array
* @param index
* @return int
*/
int add_split_node(shell_t *shell, char *cmd, char *delim);
int info_split_node(split_node_t *node, char *cmd, char *delim);
void free_split_node(shell_t *shell);

/******************************************/
/*                redirections            */
/******************************************/

int add_redirect_node(split_node_t *split, char *cmd, char *delim);
int info_red_node(red_node_t *node, char *cmd, char *delim);
void free_red_list(split_node_t *split);

/******************************************/
/*                   pipes                */
/******************************************/

int add_pipe_node(red_node_t *redirect, char *cmd, char *delim);
int info_in_pipe_node(pipe_node_t *node, char *cmd, char *delim);
void free_pipe_list(red_node_t *red);

#endif /* !PARSING_H_ */
