/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #include <sys/types.h>
    #include <stdio.h>
    #include <termios.h>

    #include "mysh/parse/parsing_infos.h"
    #include "mysh/history/history_infos.h"
    #include "mysh/alias/alias_infos.h"
    #include "mysh/list/list_infos.h"

    #define SUCCESS 0
    #define FAILURE 84

    #define ERROR_BUILTIN 1
    #define ERROR_REDIRECT 1
    #define UNKNOWN 127

    #define NOT_FOUND 0

    #define ALL "*"

typedef struct termios termios_t;

typedef struct shell_s {
    env_t env;
    path_t path;
    parsing_infos_t cmd;
    alias_t aliases;
    history_t history;
    termios_t termios;
    int is_output;
    int is_input;
    bool redirect;
    bool finished;
    int return_cmd;
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
