/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_side_functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"
#include "my.h"

void redirect(void);

Test(str_to_word_array_spaces, working, .init=redirect)
{
    char *str = "hello world\t";
    char **array = str_to_array_choice(str, " \t");

    cr_assert_str_eq(array[0], "hello");
    cr_assert_str_eq(array[1], "world");
    free_array((void **)array);
}

Test(str_to_word_array_spaces, errors_no_words_and_null, .init=redirect)
{
    char *str = "   \t \t\t    \t  ";
    char **array = str_to_array_choice(str, " 	");

    cr_assert_null(array);
    cr_assert_null(str_to_array_choice(NULL, NULL));
}

Test(cmd_handler_setenv, add_env_invalid_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *shell = malloc(sizeof(shell_t));
    char *cmd[] = {"setenv", "__ah", NULL};

    cr_assert_eq(create_env_list(eng, shell), 0);
    cmd_handler_setenv(cmd, shell);
    cr_assert_stdout_eq_str("setenv: Variable name must contain alphanumeric characters.\n");
    free_list(shell);
    free(shell);
}

Test(env_to_array, null, .init=redirect)
{
    shell_t *shell = NULL;

    cr_assert_null(env_to_array(shell));
}

Test(add_path_node, no_list)
{
    cr_assert_eq(add_path_node(NULL, NULL), 84);
}
