/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** history
*/

#ifndef HISTORY_INFOS_H_
    #define HISTORY_INFOS_H_

    #define HISTORY_FILE ".42sh_history"

typedef struct history_s {
    int fileno;
    char **history;
} history_t;

#endif /* !HISTORY_INFOS_H_ */
