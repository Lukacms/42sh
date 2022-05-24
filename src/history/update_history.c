/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** update_history
*/

#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static int get_options(char flag, shell_t *shell)
{
    if (!shell)
        return FAILURE;
    switch (flag) {
        case 'c':
            shell->history.clear = 1;
            break;
        case 'h':
            shell->history.without_number = 1;
            break;
        case 'r':
            shell->history.sort = 1;
            break;
        default:
            return FAILURE;
    }
    return SUCCESS;
}

static int error_len(int len)
{
    if (len > 3) {
        my_printf("history: Too many arguments.\n");
        return FAILURE;
    }
    return SUCCESS;
}

static int parse_history_cmd(char *cmd, shell_t *shell)
{
    char *optstring = "chr";
    int opt = 0;
    int len = 0;
    char **args = NULL;

    if (!cmd || !shell)
        return FAILURE;
    if (my_strncmp(cmd, "history ", 8) != 0)
        return SUCCESS;
    if (!(args = str_to_array_choice(cmd, " ")))
        return FAILURE;
    len = array_len(args);
    if (error_len(len) != SUCCESS)
        return FAILURE;
    optind = 1;
    while ((opt = getopt(len, args, optstring)) != -1) {
        if (get_options(opt, shell) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}

static int write_history_in_file(char *cmd, shell_t *shell)
{
    if (!cmd || !shell)
        return FAILURE;
    if (!(shell->history.fp = fopen(HISTORY_FILE, "a+")))
        return INVALID_FILE;
    fwrite(cmd, my_strlen(cmd), 1, shell->history.fp);
    fwrite("\n", 1, 1, shell->history.fp);
    fclose(shell->history.fp);
    return SUCCESS;
}

int update_history(char *cmd, shell_t *shell)
{
    int size = 0;
    int array_size = 0;

    if (!cmd || !shell)
        return FAILURE;
    if (parse_history_cmd(cmd, shell) != SUCCESS)
        return FAILURE;
    size = my_strlen(cmd);
    if (shell->history.clear) {
        free_array((void**)shell->history.history);
        shell->history.history = NULL;
        shell->history.clear = 0;
        return SUCCESS;
    }
    array_size = array_len(shell->history.history) + 1;
    shell->history.history =
        my_reallocarray(shell->history.history, array_size, size);
    shell->history.history[array_size - 1] = my_strdup(cmd);
    write_history_in_file(cmd, shell);
    return SUCCESS;
}
