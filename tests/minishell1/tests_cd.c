/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_cd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(cmd_handler_cd, going_into_tests, .init=redirect)
{
    char *cmd[] = {"cd", "tests", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=deux", "HOME=tests", "USER=oui", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 0);
    display_prompt(0, list);
    // cr_assert_stdout_eq_str("oui [0] tests $ ");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, going_into_home, .init=redirect)
{
    char *cmd[] = {"cd", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=deux", "HOME=tests", "USER=oui", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 0);
    display_prompt(0, list);
    // cr_assert_stdout_eq_str("oui [0] tests $ ");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, going_into_home_err, .init=redirect)
{
    char *cmd[] = {"cd", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=deux", "USER=oui", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 1);
    cr_assert_stdout_eq_str("cd: No home directory.\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_cd, going_oldpath, .init=redirect)
{
    char *cmd[] = {"cd", "-", NULL};
    char *const eng[] = {"PWD=", "OLDPWD=tests", "HOME=tests", "USER=oui", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(cmd_handler_cd(cmd, list), 0);
    display_prompt(0, list);
    // cr_assert_stdout_eq_str("oui [0] tests $ ");
    free_list(list);
    free(list);
}
