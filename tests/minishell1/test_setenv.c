/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** test_setenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(setenv, add_new_var_env_without_value, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    char *cmd[] = {"setenv", "a", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(cmd, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\na=\n");
    free_list(list);
    free(list);
}

Test(setenv, add_new_var_env_with_value, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    char *sec[] = {"setenv", "oui", "non", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(sec, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\noui=non\n");
    free_list(list);
    free(list);
}
