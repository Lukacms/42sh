/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** integration_test
*/

#include <unistd.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(launch, test_from_file)
{
    char * const env[] = {"PATH=/bin:/user/bin", "USER=lukac", "SHELL=/bin/mysh", NULL};
    int fileno = open("tests/minishell2/integration.txt", O_RDWR);
    char * const argv[] = {"oui"};

    if (fileno < 0)
        cr_assert_eq(0, 1);
    if (dup2(fileno, STDIN_FILENO) < 0)
        cr_assert_eq(0, 1);
    cr_assert_eq(launch(env, argv), SUCCESS);
}
