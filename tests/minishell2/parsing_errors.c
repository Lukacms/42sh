/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parsing_errors
*/

#include <unistd.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(parse_cmd, invalid_param)
{
    cr_assert_eq(parse_cmd(NULL, NULL), FAILURE);
    cr_assert_eq(parse_cmd("toto", NULL), FAILURE);
}

Test(add_nodes, null_params)
{
    cr_assert_eq(add_pipe_node(NULL, NULL, 0), FAILURE);
    cr_assert_eq(add_split_node(NULL, NULL, 0), FAILURE);
    cr_assert_eq(add_redirect_node(NULL, NULL, 0), FAILURE);
}

Test(launch, without_env)
{
    char * const env[] = {NULL};

    cr_assert_eq(launch(NULL, NULL), FAILURE);
    cr_assert_eq(launch(env, NULL), FAILURE);
}

Test(info_in_node, null_param)
{
    cr_assert_eq(info_in_pipe_node(NULL, NULL, 0), FAILURE);
    cr_assert_eq(info_red_node(NULL, NULL, 0), FAILURE);
    cr_assert_eq(info_split_node(NULL, NULL, 0), FAILURE);
}

Test(free, null_params_for_free)
{
    free_pipe_list(NULL);
    free_red_list(NULL);
    free_split_node(NULL);
}

Test(exec, null_params_exec)
{
    red_node_t red = {0};
    split_node_t split = {0};

    cr_assert_eq(pipe_cmd_loop(NULL, NULL), SUCCESS);
    cr_assert_eq(pipe_cmd_loop(&red, NULL), SUCCESS);

    cr_assert_eq(cmd_handler_exit(NULL, NULL), 1);

    cr_assert_eq(double_left_redirect(NULL, NULL, NULL), SUCCESS);
    cr_assert_eq(double_left_redirect(&red, NULL, NULL), SUCCESS);

    cr_assert_eq(left_redirect(NULL, NULL, NULL), SUCCESS);
    cr_assert_eq(left_redirect(&red, NULL, NULL), SUCCESS);
    cr_assert_eq(left_redirect(&red, &split, NULL), SUCCESS);

    cr_assert_eq(right_redirect(NULL, NULL, NULL), SUCCESS);
    cr_assert_eq(right_redirect(&red, NULL, NULL), SUCCESS);
    cr_assert_eq(right_redirect(&red, &split, NULL), SUCCESS);

    cr_assert_eq(double_right_redirect(NULL, NULL, NULL), SUCCESS);
    cr_assert_eq(double_right_redirect(&red, NULL, NULL), SUCCESS);
    cr_assert_eq(double_right_redirect(&red, &split, NULL), SUCCESS);
}

Test(double_left_redirect, test_double_left)
{
    shell_t shell = {0};
    int fd = open("tests/minishell2/double_left.txt", O_RDONLY);

    cr_assert_geq(dup2(fd, STDIN_FILENO), 0);
    cr_assert_eq(parse_cmd("ls << eof src", &shell), SUCCESS);
    cr_assert_eq(double_left_redirect(shell.cmd.head->head->prev, shell.cmd.head, &shell), SUCCESS);
}
