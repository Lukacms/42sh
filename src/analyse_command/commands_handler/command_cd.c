/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-chloe.camus
** File description:
** command_cd
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int get_usr_to_home(shell_t *shell)
{
    env_node_t *node = find_variable_by_name(shell, "HOME");
    env_node_t *pwd_node = find_variable_by_name(shell, "PWD");
    int status = 0;

    if (!node) {
        my_printf("cd: No home directory.\n");
        return ERROR_BUILTIN;
    }
    if ((status = chdir(node->var_value)) < 0) {
        my_printf("%s: %s.\n", node->var_value, strerror(errno));
        return ERROR_BUILTIN;
    } else {
        if (pwd_node)
            replace_variable_value(shell, "OLDPWD", pwd_node->var_value);
        replace_variable_value(shell, "PWD", node->var_value);
    }
    return SUCCESS;
}

static int change_dir(char **array, shell_t *shell)
{
    int status = 0;
    char *value = getcwd(NULL, 0);

    if ((status = chdir(array[1])) < 0) {
        my_printf("%s: %s.\n", array[1], strerror(errno));
        return ERROR_BUILTIN;
    } else {
        replace_variable_value(shell, "OLDPWD", value);
        free(value);
        value = getcwd(NULL, 0);
        replace_variable_value(shell, "PWD", value);
    }
    free(value);
    return SUCCESS;
}

static int get_to_old_pwd(shell_t *shell)
{
    char *value = NULL;
    char *old_value = NULL;
    env_node_t *oldpwd_node = find_variable_by_name(shell, "OLDPWD");
    int status = 0;

    if (oldpwd_node == NULL)
        return ERROR_BUILTIN;
    old_value = getcwd(NULL, 0);
    if ((status = chdir(oldpwd_node->var_value)) < 0) {
        my_printf("%s: %s.\n", oldpwd_node->var_value, strerror(errno));
        return ERROR_BUILTIN;
    } else {
        value = getcwd(NULL, 0);
        replace_variable_value(shell, "OLDPWD", old_value);
        replace_variable_value(shell, "PWD", value);
    }
    free(old_value);
    free(value);
    return SUCCESS;
}

int cmd_handler_cd(char **array, shell_t *shell)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    if (i > 2)
        return my_printf("cd: Too many arguments.\n");
    if (i == 1 || (i == 2 && my_strcmp(array[1], "--") == 0))
        return get_usr_to_home(shell);
    else if (my_strcmp(array[1], "-") == 0)
        return get_to_old_pwd(shell);
    return change_dir(array, shell);
}
