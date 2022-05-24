/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** special_variables
*/

#ifndef SPECIAL_VARIABLES_H_
    #define SPECIAL_VARIABLES_H_

    #include "mysh/infos.h"

typedef char *(*special_variable_handler)(shell_t *shell, char *line);

typedef struct variable_handling_s {
    char *variable;
    special_variable_handler handler;
} variable_handling_t;

char **special_variables(char **og, shell_t *shell);

// fucntion pointers for special variables
char *dollard_handler(shell_t *shell, char *line);
char *exclamation_handler(shell_t *shell, char *line);
char *hashtag_handler(shell_t *shell, char *line);
char *interogation_handler(shell_t *shell, char *line);
char *underscore_handler(shell_t *shell, char *line);
char *zero_handler(shell_t *shell, char *line);

#endif /* !SPECIAL_VARIABLES_H_ */
