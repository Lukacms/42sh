/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_errors_for_builtsin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(cmd_handler_cd, too_much_arguments_cd, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"cd", "hey", "too much", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_neq(cmd_handler_cd(cmd, list), 1);
    cr_assert_stdout_eq_str("cd: Too many arguments.\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_setenv, too_much_arguments_setenv, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", "hey", "too", "much", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_setenv(cmd, list), 1);
    cr_assert_stdout_eq_str("setenv: too many arguments\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_unsetenv, too_much_arguments_unsetenv, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"unsetenv", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_unsetenv(cmd, list), 1);
    cr_assert_stdout_eq_str("unsetenv: too few arguments\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, going_into_home_err_available, .init=redirect)
{
    char *cmd[] = {"cd", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=deux", "HOME=Makefile", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 1);
    cr_assert_stdout_eq_str("Makefile: Not a directory.\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, going_into_Makefile, .init=redirect)
{
    char *cmd[] = {"cd", "Makefile", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 1);
    cr_assert_stdout_eq_str("Makefile: Not a directory.\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, inexisting_oldpwd, .init=redirect)
{
    char *cmd[] = {"cd", "-", NULL};
    char *const eng[] = {"PWD=", "two=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 1);
    display_prompt(0, list);
    // cr_assert_stdout_eq_str("oui [0] 42sh $ ");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, incorrect_oldpwd, .init=redirect)
{
    char *cmd[] = {"cd", "-", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=Makefile", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 1);
    cr_assert_stdout_eq_str("Makefile: Not a directory.\n");
    free_list(list);
    free(list);
}
