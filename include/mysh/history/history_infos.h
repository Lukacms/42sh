/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** history
*/

#ifndef HISTORY_INFOS_H_
    #define HISTORY_INFOS_H_

    #include <fcntl.h>
    #include <getopt.h>

    #define HISTORY_FILE ".42sh_history"
    #define OPT_HISTORY_STRING "chr"

    #define INVALID_FILE 84
    #define FILE_INIT_CORRECT 0

typedef struct history_s {
    FILE *fp;
    char **history;
    bool without_number;
    bool sort;
    bool clear;
} history_t;

#endif /* !HISTORY_INFOS_H_ */
