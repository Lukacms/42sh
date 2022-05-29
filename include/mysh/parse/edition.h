/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** edition
*/

#ifndef EDITION_H_
    #define EDITION_H_

    #include "mysh/infos.h"

typedef int (*special_char_handler_t)(shell_t *shell, char **line, int *n);

typedef struct char_handler_s {
    int c;
    special_char_handler_t handler;
} char_handler_t;

int analyse_char(int c, shell_t *shell, char **line, int *n);

// fucntion pointers for special chars
int key_up_handler(shell_t *shell, char **line, int *n);
int key_down_handler(shell_t *shell, char **line, int *n);
int key_left_handler(shell_t *shell, char **line, int *n);
int key_right_handler(shell_t *shell, char **line, int *n);
int ctrl_l_handler(shell_t *shell, char **line, int *n);
int delete_handler(shell_t *shell, char **line, int *n);

// inhibitor
char **inhibitor(char **og);

#endif /* !EDITION_H_ */
