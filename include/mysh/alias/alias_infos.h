/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** alias_infos
*/

#ifndef ALIAS_INFOS_H_
    #define ALIAS_INFOS_H_

typedef struct alias_node_s {
    char *name;
    char **value;
    struct alias_node_s *prev;
    struct alias_node_s *next;
} alias_node_t;

typedef struct alias_s {
    alias_node_t *head;
    unsigned int size;
} alias_t;

#endif /* !ALIAS_INFOS_H_ */
