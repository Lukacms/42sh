/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** edition
*/

#ifndef EDITION_H_
    #define EDITION_H_

    #include "mysh/infos.h"

typedef int (*special_char_handler_t)(shell_t *shell);

typedef struct char_handler_s {
    int c;
    special_char_handler_t handler;
} char_handler_t;

#endif /* !EDITION_H_ */
