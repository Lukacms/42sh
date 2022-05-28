/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parsing_infos
*/

#ifndef PARSING_INFOS_H_
    #define PARSING_INFOS_H_

    #include <fcntl.h>
    #include <sys/types.h>
    #include <stdbool.h>

    #define SEPARATOR "\t "
    #define MAGIC_QUOTE '`'
    #define QUOTATION "\"'`"

    #define SIMPLE (O_CREAT | O_TRUNC | O_RDWR)
    #define DOUBLE (O_CREAT | O_APPEND | O_RDWR)
    #define MODE 0666

    #define PIPE_NULL "Invalid null command.\n"
    #define MISMATCHED_PARSING "Unmatched '%c'.\n"

typedef enum redirect {
    LEFT_REDIRECT,
    RIGHT_REDIRECT,
    DOUBLE_LEFT,
    DOUBLE_RIGHT,
    R_NOTHING
} redirect_type_t;

typedef enum split {
    SEMICOLON,
    DOUBLE_AMPERSAND,
    DOUBLE_VBAR,
    NOTHING
} split_type_t;

typedef struct magic_node_s {
    char *cmd;
    struct magic_node_s *prev;
    struct magic_node_s *next;
} magic_node_t;

typedef struct pipe_node_s {
    char **cmd;
    bool prev_pipe;
    bool next_pipe;
    magic_node_t *head;
    unsigned int size;
    struct pipe_node_s *prev;
    struct pipe_node_s *next;
} pipe_node_t;

typedef struct red_node_s {
    pipe_node_t *head;
    unsigned int size;
    redirect_type_t prev_red;
    redirect_type_t next_red;
    struct red_node_s *prev;
    struct red_node_s *next;
} red_node_t;

typedef struct split_node_s {
    red_node_t *head;
    unsigned int size;
    split_type_t prev_split;
    split_type_t next_split;
    struct split_node_s *prev;
    struct split_node_s *next;
} split_node_t;

typedef struct parsing_infos_s {
    split_node_t *head;
    unsigned int size;
} parsing_infos_t;

typedef struct next_type_handler_s {
    char *red;
    redirect_type_t type;
    split_type_t split;
} next_type_handler_t;

#endif /* !PARSING_INFOS_H_ */
