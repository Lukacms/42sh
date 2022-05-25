/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** apply_mods
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

static int cmp_arrays(char **src, char **cmp)
{
    for (int i = 0; src[i] && cmp[i]; i++)
        if (my_strcmp(src[i], cmp[i]))
            return FAILURE;
    return SUCCESS;
}

static int glob_inside(char *str, char c)
{
    if (!str)
        return FAILURE;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

static char **clean_tab(char **tab)
{
    char **temp = NULL;
    int len = 0;
    int i = 0;

    while (tab[len]) {
        if (glob_inside(tab[i], '?') != 1)
            len++;
    }
    temp = malloc(sizeof(char *) * (len + 1));
    for (; tab[i]; i++) {
        if (glob_inside(tab[i], '?') != 1) {
            temp[i] = my_strdup(tab[i]);
        }
    }
    return temp;
}

char **globbing(char *str, char **dest)
{
    glob_t globb;
    int status = 0;
    char **tab = NULL;

    if (!str || !dest || !(*dest))
        return NULL;
    status = glob(str, GLOB_NOSORT | GLOB_ERR, NULL, &globb);
    if (status != 0) {
        if (status == GLOB_NOMATCH)
            printf("No match.\n");
        return NULL;
    }
    //printf("Found %zu filename matches\n",globb.gl_pathc);
    tab = globb.gl_pathv;
    tab = concate_arrays(dest, tab);
    //tab = clean_tab(tab);
    my_printf("---------\n");
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
    my_printf("---------\n");
    globfree(&globb);
    return tab;
}

char **apply_mods(char **og, shell_t *shell)
{
    char **new = NULL;
    char **dest = NULL;

    if (!og || !shell)
        return og;
    if ((new = analyse_aliases(og[0], shell)))
        dest = concate_arrays(new, og + 1);
    new = NULL;
    while (dest && (new = analyse_aliases(dest[0], shell)) &&
        cmp_arrays(new, dest))
        dest = concate_arrays(new, dest + 1);
    for (int i = 0; og[i]; i++) {
        dest = globbing(og[i], og);
    }
    if (!dest)
        return og;
    return dest;
}
