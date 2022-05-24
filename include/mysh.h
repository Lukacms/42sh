/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_

    #include "mysh/infos.h"
    #include "mysh/list/list.h"
    #include "mysh/history/history.h"
    #include "mysh/alias/alias.h"
    #include "mysh/commands.h"
    #include "mysh/parse/parsing.h"
    #include "mysh/parse/edition.h"
    #include "mysh/kernel/kernel_params.h"

/*
* @brief base for algortithm - main loop which get the arguments
*
* @param env
* @return int - SUCCESS | FAILURE
*/
int launch(char *const env[]);

/*
* @brief Create a shell object
*
* @param shell
* @return int
*/
int create_shell(shell_t *shell, char * const env[]);

/*
* @brief display of prompt
*
* @param status
* @param shell
*/
void display_prompt(int status, shell_t *shell);

#endif /* !MYSH_H_ */
