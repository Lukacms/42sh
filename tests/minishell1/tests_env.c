/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//don't do that
/*Test(create_env_list, empty_environment)
{
    char **eng = NULL;

    cr_assert_eq(create_env_list(eng, NULL), 84);
    cr_assert_eq(launch(eng), 84);
    cr_assert_eq(cmd_handler_env(NULL, NULL), 0);
}*/

Test(cmd_handler_env, display_env, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\n");
    free_list(list);
    //test an error with env
    cr_assert_neq(cmd_handler_env(NULL, list), 0);
    free_list(list);
    free(list);
}

Test(cmd_handler_setenv, display_env_with_setenv, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(cmd, list);
    cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_setenv, add_env_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", "123oui", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(cmd, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\n123oui=\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_unsetenv, del_env_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"unsetenv", "third", "second", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_unsetenv(cmd, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=un\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_unsetenv, del_all, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"unsetenv", "*", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_unsetenv(cmd, list);
    cr_assert_eq(list->env.size, 0);
    cr_assert_eq(cmd_handler_env(NULL, list), 1);
    free_list(list);
    free(list);
}

Test(cmd_handler_setenv, add_env_node_without_env, .init=redirect)
{
    char *const eng[] = {NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", "123oui", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(cmd, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("123oui=\n");
    free_list(list);
    free(list);
}

Test(cmd_handler_setenv, modify_env_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", "first", "oui", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cmd_handler_setenv(cmd, list);
    cmd_handler_env(NULL, list);
    cr_assert_stdout_eq_str("first=oui\nsecond=deux\nthird=trois\n");
    free_list(list);
    free(list);
}
