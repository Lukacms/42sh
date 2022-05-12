/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parsing_infos
*/

#ifndef PARSING_INFOS_H_
    #define PARSING_INFOS_H_

    #include <sys/types.h>
    #include <stdbool.h>

    #define SEPARATOR "\t "

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

typedef struct pipe_node_s {
    char **cmd;
    bool prev_pipe;
    bool next_pipe;
    struct pipe_node_s *prev;
    struct pipe_node_s *next;
} pipe_node_t;

typedef struct red_node_s {
    pipe_node_t *head;
    u_int size;
    redirect_type_t prev_red;
    redirect_type_t next_red;
    struct red_node_s *prev;
    struct red_node_s *next;
} red_node_t;

typedef struct split_node_s {
    red_node_t *head;
    u_int size;
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
