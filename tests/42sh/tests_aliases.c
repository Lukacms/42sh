/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** tests_aliases
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

/**
 * @brief Test basic functionnalities of alias builtin
 *
 */
Test(cmd_handler_alias, add_aliases, .init=redirect)
{
    char * const env[] = {"oui=non", "TERM=xterm-256color", NULL};
    char * const argv[] = {"unit_test"};
    shell_t shell = {0};
    char *cmd1[] = {"alias", "ls", "ls", "-l", NULL};
    char *cmd2[] = {"alias", "clear", "clear", "-x", NULL};
    char *cmd3[] = {"alias", "clear", "clear", "-h", NULL};
    char *alias[] = {"alias", NULL};
    char *alias_ls[] = {"alias", "ls", NULL};

    create_shell(&shell, env, argv);
    cr_assert_eq(cmd_handler_alias(cmd1, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_alias(cmd2, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_alias(cmd3, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_alias(alias, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_alias(alias_ls, &shell), SUCCESS);
    destroy_shell(&shell);
}

Test(cmd_handler_alias, null_exception_test)
{
    char * const env[] = {"oui=non", "TERM=xterm-256color", NULL};
    char * const argv[] = {"unit_test"};
    shell_t shell = {0};
    char *alias[] = {"alias", NULL};
    char *alias_ls[] = {"alias", "ls", NULL};

    create_shell(&shell, env, argv);
    cr_assert_eq(cmd_handler_alias(NULL, NULL), ERROR_BUILTIN);
    cr_assert_eq(cmd_handler_alias(alias, &shell), ERROR_BUILTIN);
    cr_assert_eq(cmd_handler_alias(alias_ls, &shell), ERROR_BUILTIN);
    destroy_shell(&shell);
}

Test(cmd_handler_unalias, unalias_tests, .init=redirect)
{
    shell_t shell = {0};
    char *cmd1[] = {"alias", "ls", "ls", "-l", NULL};
    char *cmd2[] = {"alias", "clear", "clear", "-x", NULL};
    char *cmd4[] = {"unalias", "ls", NULL};
    char *cmd5[] = {"unalias", "*", NULL};

    cr_assert_eq(cmd_handler_alias(cmd1, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_alias(cmd2, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_unalias(cmd4, &shell), SUCCESS);
    cr_assert_eq(cmd_handler_unalias(cmd5, &shell), SUCCESS);
    destroy_shell(&shell);
}

Test(cmd_handler_unalias, errors_unalias_null_args)
{
    shell_t shell = {0};
    char *cmd[] = {"unalias", NULL};

    cr_assert_eq(cmd_handler_alias(NULL, NULL), ERROR_BUILTIN);
    cr_assert_eq(cmd_handler_alias(cmd, NULL), ERROR_BUILTIN);
    cr_assert_eq(cmd_handler_alias(cmd, &shell), ERROR_BUILTIN);
    destroy_shell(&shell);
}

Test(add_alias_node, arg_nulls_addaliasnode)
{
    char cmd[] = "oui";
    char *value[] = {"ouimaisenarray", NULL};

    cr_assert_eq(add_alias_node(NULL, NULL, NULL), FAILURE);
    cr_assert_eq(add_alias_node(cmd, NULL, NULL), FAILURE);
    cr_assert_eq(add_alias_node(cmd, value, NULL), FAILURE);
}

Test(delete_all_aliases, arg_nulls)
{
    alias_node_t node = {0};

    cr_assert_eq(delete_all_aliases(NULL), NOT_FOUND);
    cr_assert_eq(print_alias_value(NULL, false), FAILURE);
    cr_assert_eq(replace_alias(NULL, NULL), FAILURE);
    cr_assert_eq(replace_alias(&node, NULL), FAILURE);
}
