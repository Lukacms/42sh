/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** history
*/

#ifndef HISTORY_H_
    #define HISTORY_H_

    #include "mysh/infos.h"

/*
* @brief init history part for shell
*
* @param history
* @return int
*/
int init_history(history_t *history);

/*
* @brief add each command when typed
*
* @param cmd
* @param shell
* @return int
*/
int update_history(char *cmd, shell_t *shell);

#endif /* !HISTORY_H_ */
