/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** test_42_integration
*/

#include <unistd.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

char const filepath[] = "./tests/assets/42_integration.txt";

void redirect(void);

Test(launch, test_integration_42)
{
    char * const env[] = {"PATH=/bin:/user/bin", "USER=lukac", "SHELL=/bin/mysh",
    "TERM=xterm-256color", NULL};
    int fileno = open(filepath, O_RDWR);
    char * const argv[] = {"oui"};

    if (fileno < 0)
        cr_assert_eq(0, 2);
    if (dup2(fileno, STDIN_FILENO) < 0)
        cr_assert_eq(0, 1);
    cr_assert_eq(launch(env, argv), SUCCESS);
}
