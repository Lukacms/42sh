/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** test_exit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(cmd_handler_exit, test_for_exit, .init=redirect)
{
    cr_assert_eq(cmd_handler_exit(NULL, NULL), 1);
}
