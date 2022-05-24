/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** special_variables_infos
*/

#ifndef SPECIAL_VARIABLES_INFOS_H_
    #define SPECIAL_VARIABLES_INFOS_H_

typedef int return_t;

typedef struct special_variables_infos_s {
    return_t status;
    char *current_script;
    char **last;
} special_variables_infos_t;

#endif /* !SPECIAL_VARIABLES_INFOS_H_ */
