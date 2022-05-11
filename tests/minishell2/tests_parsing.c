/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(parse_cmd, valid_with_everything)
{
    shell_t *shell = malloc(sizeof(shell_t));
    char *cmd = "ls | cat -e > file ; cat << Makefile && toto < tata || tutu >> titi";
    char * const env[] = {"toto=tutu", "tata=titi", NULL};

    if (!shell)
        cr_assert_eq(0, 1);
    cr_assert_eq(create_env_list(env, shell), SUCCESS);
    cr_assert_eq(parse_cmd(cmd, shell), SUCCESS);
    free_split_node(shell);
    free_list(shell);
}
