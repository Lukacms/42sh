/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #include <sys/types.h>
    #include "mysh/parse/parsing_infos.h"

typedef struct env_node_s {
    char *var_name;
    char *var_value;
    struct env_node_s *prev;
    struct env_node_s *next;
} env_node_t;

typedef struct path_node_s {
    char *path;
    struct path_node_s *prev;
    struct path_node_s *next;
} path_node_t;

typedef struct alias_node_s {
    char *name;
    char **value;
    struct alias_node_s *prev;
    struct alias_node_s *next;
} alias_node_t;

typedef struct shell_s {
    struct {
        env_node_t *head;
        unsigned int size;
    } env;
    struct {
        path_node_t *head;
        unsigned int size;
    } path;
    struct {
        split_node_t *head;
        u_int size;
    } cmd;
    struct {
        alias_node_t *head;
        unsigned int size;
    } aliases;
    int is_output;
    int is_input;
    bool redirect;
    bool finished;
} shell_t;

typedef int (*command_handler_t)(char **array, shell_t *shell);

typedef struct command_handler_binder_s {
    char *existing_command;
    command_handler_t handler;
} command_handler_binder_t;

typedef int (*redirect_handler_t)(red_node_t *node, split_node_t *split,
shell_t *shell);

typedef struct redirect_handler_binder_s {
    redirect_type_t type;
    redirect_handler_t handler;
} redirect_handler_binder_t;

#endif /* !INFOS_H_ */
