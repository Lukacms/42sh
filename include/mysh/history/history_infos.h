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
    #define HISTORY_FLAGS (O_CREAT | O_APPEND | O_RDWR)
    #define FILE_MODE 0666

    #define INVALID_FILE 84
    #define FILE_INIT_CORRECT 0

typedef struct history_s {
    int fileno;
    char **history;
    bool without_number;
    bool sort;
    bool clear;
} history_t;

#endif /* !HISTORY_INFOS_H_ */
