/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include <sys/types.h>
    #include <stdio.h>
    #include "mysh/infos.h"

    #define END '\n'
    #define NO_INVALID_READ '\0'

/*
* @brief reproduce getline for shell, to analyse
*
* @param shell
* @param ptr
* @param n
* @param fd
* @return ssize_t
*/
ssize_t getshellline(shell_t *shell, char **ptr, size_t *n, FILE *stream);

/*
* @brief analyse command, with redirect
*
* @param shell
* @param cmd_str
* @return int
*/
int get_commands(shell_t *shell, char *cmd_str);

/*
* @brief apply any necessary modifications into a command
*
* @param og
* @param shell
* @return char** | NULL
*/
char **apply_mods(char **og, shell_t *shell);

/*
* @brief Get the commands object
*
* @param cmd_array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int analyse_cmd(char **cmd_array, shell_t *shell);

/*
* @brief cmd_handler: cd
*
* @param array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int cmd_handler_cd(char **array, shell_t *shell);

/*
* @brief cmd_handler: env
*
* @param array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int cmd_handler_env(char **array, shell_t *shell);

/*
* @brief cmd_handler: exit
*
* @param array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int cmd_handler_exit(char **array, shell_t *shell);

/*
* @brief cmd_handler: setenv
*
* @param array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int cmd_handler_setenv(char **array, shell_t *shell);

/*
* @brief cmd_handler: alias
*
* @param array
* @param shell
* @return int
*/
int cmd_handler_alias(char **array, shell_t *shell);

/*
* @brief cmd_handler: unalias (delete alias)
*
* @param array
* @param shell
* @return int
*/
int cmd_handler_unalias(char **array, shell_t *shell);

/*
* @brief cmd_handler: unsetenv
*
* @param array
* @param shell
* @return int - SUCCESS | FAILURE
*/
int cmd_handler_unsetenv(char **array, shell_t *shell);

/*
* @brief cmd_handler: history
*
* @param array
* @param shell
* @return int
*/
int cmd_handler_history(char **array, shell_t *shell);

/*
* @brief execute possible binaries
*
* @param shell
* @param cmd
* @return int - SUCCESS | FAILURE
*/
int execute_command(shell_t *shell, char **cmd);

/*
* @brief execute specific binaries concated wit env variables
*
* @param cmd
* @param args
* @param env
* @return int - SUCCESS | FAILURE
*/
int execute_binary(char const *cmd, char *const args[], char *const env[],
                    shell_t *shell);

/*
* @brief concate cmd with path variables
*
* @param shell
* @param cmd
* @param env
* @return int - SUCCESS | FAILURE
*/
int search_command_in_path(shell_t *shell, char **cmd, char *const env[]);

/*
* @brief get env shell to an array for execve
*
* @param shell
* @return char** | NULL
*/
char **env_to_array(shell_t *shell);
char **my_clean_array(char **array);

int loop_pipe(red_node_t *red, shell_t *shell);
int simple_cmd(pipe_node_t *pipe, shell_t *shell);
int red_cmd_loop(split_node_t *head, shell_t *shell);
int pipe_cmd_loop(red_node_t *red, shell_t *shell);
int split_cmd_loop(shell_t *shell);

int double_left_redirect(red_node_t *node, split_node_t *split,
    shell_t *shell);
int double_right_redirect(red_node_t *node, split_node_t *split,
    shell_t *shell);
int left_redirect(red_node_t *node, split_node_t *split, shell_t *shell);
int right_redirect(red_node_t *node, split_node_t *split, shell_t *shell);
int beheads_node(red_node_t *red);
int concate_nodes(red_node_t *concate, red_node_t *from);
int execute_pipe(pipe_node_t *node, int **fd, unsigned int i, shell_t *shell);
int check_errors_left(red_node_t *node, red_node_t *concate, shell_t *shell);
int check_errors_right(red_node_t *node, shell_t *shell);
int check_unique_errors(red_node_t *node);

#endif /* !COMMANDS_H_ */
