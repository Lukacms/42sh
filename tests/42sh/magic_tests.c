/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** magic_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(get_commands, normal_magic)
{
    char * const env[] = {"oui=non", "TERM=xterm-256color", NULL};
    char * const argv[] = {"unit_test"};
    shell_t shell = {0};
    char cmd[] = "ls `ls` src `ls | cat -e`";

    create_shell(&shell, env, argv);
    cr_assert_eq(get_commands(&shell, cmd), 512);
}
