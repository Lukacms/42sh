/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** tests_execute_binary
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mysh.h"

void redirect(void);

Test(execute_command, no_linked_list, .init=redirect)
{
    cr_assert_eq(execute_command(NULL, NULL), 0);
}

Test(execute_command, segfault_program, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"./tests/assets/my_segfault", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_neq(execute_command(list, cmd), 0);
    cr_assert_stdout_eq_str("Segmentation fault (core dumped)\n");
    free_list(list);
    free(list);
}

Test(execute_command, without_fullpath, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=./tests/assets", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"my_ls", "-d", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(create_path_list(list), 0);
    cr_assert_eq(execute_command(list, cmd), 0);
    cr_assert_stdout_eq_str(".\n");
    free_paths_nodes(list);
    free_list(list);
    free(list);
}

Test(execute_command, inexisting_programm, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"ah", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_neq(execute_command(list, cmd), 0);
    cr_assert_stdout_eq_str("ah: Command not found.\n");
    free_list(list);
    free(list);
}

Test(execute_command, inexisting_programm_fullpath, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"./ah", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(execute_command(list, cmd), 127);
    cr_assert_stdout_eq_str("./ah: Command not found.\n");
    free_list(list);
    free(list);
}

Test(execute_command, trying_inexecutable, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"./Makefile", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(execute_command(list, cmd), 0);
    cr_assert_stdout_eq_str("./Makefile: Permission denied.\n");
    free_list(list);
    free(list);
}

Test(execute_command, windows_on_linux, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=deux", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"./tests/assets/SteamSetup.exe", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(execute_command(list, cmd), 0);
    cr_assert_stdout_eq_str("./tests/assets/SteamSetup.exe: Exec format error. Wrong Architecture.\n");
    free_list(list);
    free(list);
}

Test(execute_command, searching_in_paths, .init=redirect)
{
    char *const eng[] = {"first=un", "PATH=tests:tests/assets", "third=trois", NULL};
    shell_t *list = malloc(sizeof(shell_t));
    char *cmd[] = {"my_ls", NULL};

    cr_assert_eq(create_env_list(eng, list), 0);
    cr_assert_eq(create_path_list(list), 0);
    cr_assert_eq(search_command_in_path(list, cmd, eng), UNKNOWN);
    free_paths_nodes(list);
    free_list(list);
    free(list);
}
