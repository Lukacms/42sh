/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** test_prompt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(display_prompt, prompt_displaying, .init=redirect)
{
    display_prompt(0, NULL);
    cr_assert_stdout_eq_str(" [0] 42sh $ ");
}
