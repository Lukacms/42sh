/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** list_infos
*/

#ifndef LIST_INFOS_H_
    #define LIST_INFOS_H_

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

typedef struct env_s {
    env_node_t *head;
    unsigned int size;
} env_t;

typedef struct path_s {
    path_node_t *head;
    unsigned int size;
} path_t;

#endif /* !LIST_INFOS_H_ */
