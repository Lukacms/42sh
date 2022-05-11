/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_env_functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(add_path_node, arg_given_is_null)
{
    cr_assert_eq(add_node(NULL, NULL), 84);
}

Test(create_env_list, errors_with_list_and_env)
{
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(NULL, NULL), 84);
    cr_assert_eq(create_env_list(NULL, list), 84);
    free(list);
}

Test(free_specific_node, non_existing_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    free_specific_node(list, "non_existing");
    cr_assert_eq(list->env.size, 3);
    free_list(list);
    free(list);
}

Test(free_specific_node, node_is_head, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    free_specific_node(list, "first");
    cr_assert_eq(list->env.size, 2);
    free_list(list);
    free(list);
}

Test(replace_variable_value, replace_inexisting_node, .init=redirect)
{
    char *const eng[] = {"first=un", "second=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(replace_variable_value(list, "non_existing", "nothing"), 0);
    cr_assert_eq(list->env.size, 4);
    free_list(list);
    free(list);
}
