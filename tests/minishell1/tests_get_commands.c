/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_analyse_cmd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(cmd_handler_unsetenv, invalid_string, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *shell = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, shell), 0);
    free_list(shell);
    free(shell);
}

// Test(cmd_handler_unsetenv, exit_cmd, .init=redirect)
// {
//     char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
//     shell_t *shell = malloc(sizeof(shell_t));
//     char **str = {"exit", NULL};

//     cr_assert_eq(create_env_list(eng, list), 0);
//     cr_assert_eq(analyse_cmd(str, list), 0);
//     cr_assert_eq(list->finished, 1);
//     free_list(list);
//     free(list);
// }

// Test(cmd_handler_unsetenv, env, .init=redirect)
// {
//     char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
//     shell_t *shell = malloc(sizeof(shell_t));
//     char **str = {"env", NULL};

//     cr_assert_eq(create_env_list(eng, list), 0);
//     cr_assert_eq(analyse_cmd(str, list), 0);
//     cr_assert_stdout_eq_str("first=un\nsecond=deux\nthird=trois\n");
//     free_list(list);
//     free(list);
// }

// Test(cmd_handler_unsetenv, invalid_paths, .init=redirect)
// {
//     char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
//     shell_t *shell = malloc(sizeof(shell_t));
//     char **str = {"ls", NULL};

//     cr_assert_eq(create_env_list(eng, list), 0);
//     cr_assert_eq(analyse_cmd(str, list), 0);
//     free_list(list);
//     free(list);
// }

// Test(cmd_handler_unsetenv, launching_binary, .init=redirect)
// {
//     char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
//     shell_t *shell = malloc(sizeof(shell_t));
//     char **str = {"./tests/assets/my_ls", "include", NULL};

//     cr_assert_eq(create_env_list(eng, list), 0);
//     cr_assert_eq(analyse_cmd(str, list), 0);
//     cr_assert_stdout_eq_str("my.h\nmysh.h\n\n");
//     free_list(list);
//     free(list);
// }
