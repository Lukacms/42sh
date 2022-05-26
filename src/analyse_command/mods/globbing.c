/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** globbing
*/

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include <errno.h>
#include "mysh.h"
#include "my.h"

static const char flag[] = {'?','*', '~', '!', '[', ']', '\0'};

static int which_flags(char *str, int i)
{
    for (int j = 0; flag[j] != '\0'; j++) {
        if (str[i] == flag[j])
            return 1;
    }
    return 0;
}

int glob_inside(char *str)
{
    if (!str)
        return FAILURE;
    for (int i = 0; str[i] != '\0'; i++) {
        if (which_flags(str, i) == 1)
            return 1;
    }
    return 0;
}

static char **do_gloobing(char *cmd, int *stat, char *binary, int *mods)
{
    int status = 0;
    char **tab = NULL;
    glob_t globb = {0};

    if (!cmd || !glob_inside(cmd))
        return NULL;
    status = glob(cmd, GLOB_ERR | GLOB_TILDE, NULL, &globb);
    if (status != 0) {
        if (status == GLOB_NOMATCH)
            printf("%s: No match.\n", binary);
        *stat = FAILURE;
        return NULL;
    }
    *mods += 1;
    tab = dup_array(globb.gl_pathv);
    globfree(&globb);
    return tab;
}

char **my_concat_tab(char **a, char **b)
{
    int index = 0;
    int len_a = array_len(a);
    int len_b = array_len(b);
    char **tab = malloc(sizeof(char *) * (len_a + len_b + 1));

    if (a)
        for (; a[index] != NULL; ++index)
            tab[index] = my_strdup(a[index]);
    if (b) {
        for (int i = 0; b[i] != NULL; ++i) {
            tab[index] = my_strdup(b[i]);
            ++index;
        }
    }
    tab[(array_len(a) + array_len(b))] = NULL;
    return (tab);
}

char **my_globbing(char **dest)
{
    char **new = NULL;
    char **tab = NULL;
    int status = 0;
    int modified = 0;

    if (!dest)
        return NULL;
    for (int i = 0; dest[i] != NULL; i++) {
        tab = do_gloobing(dest[i], &status, dest[0], &modified);
        new = my_concat_tab(new, tab);
        free_array((void **)tab);
    }
    if (status != 0)
        return NULL;
    tab = my_clean_array(dest, modified);
    new = concate_arrays(tab, new);
    free_array((void **)tab);
    return new;
}
