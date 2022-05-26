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

static int glob_inside(char *str, char c)
{
    if (!str)
        return FAILURE;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

static char **do_gloobing(char *cmd)
{
    int status = 0;
    char **tab = NULL;
    glob_t globb = {0};

    if (!cmd)
        return NULL;
    status = glob(cmd, GLOB_ERR, NULL, &globb);
    if (status != 0) {
        if (status == GLOB_NOMATCH)
            printf("No match.\n");
        return NULL;
    }
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

char **clean_array(char **tab)
{
    int len_tab = array_len(tab);
    int index = 0;
    char **result = malloc(sizeof(char *) * (len_tab + 1));

    if (tab) {
        for (int i = 0; tab[i] != NULL; ++i) {
            if (glob_inside(tab[i], '?'))
                continue;
            result[index] = my_strdup(tab[i]);
            index++;
        }
    }
    result[len_tab] = NULL;
    free_array((void **)tab);
    return result;
}

char **my_globbing(char **dest)
{
    char **new = NULL;
    char **tab = NULL;
    int j = 0;
    int len = 0;
    int len_tab = 0;

    for (int i = 0; dest && dest[i] != NULL; i++) {
        tab = do_gloobing(dest[i]);
        new = my_concat_tab(dest, tab);
        /* CLEAN_ARRAY */
        //new = clean_array(new);
        //ou bien tab = ls src ==> ls src src  --> new = ls src
        //1er tour = tab ==> ls ?rc ?nclude src et new ==> NULL -->new = ls src /
        //2eme tour = tab = ls ?rc ?nclude include et new ==> ls src -> new = ls src include
        // len = array_len(tab) + 1;
        // len_tab = array_len(dest) + 1;
        for (int i = 0; new[i]; i++) {
            printf("------> %s\n", new[i]);
        }
    }
    return new;
}

static int cmp_arrays(char **src, char **cmp)
{
    for (int i = 0; src[i] && cmp[i]; i++)
        if (my_strcmp(src[i], cmp[i]))
            return FAILURE;
    return SUCCESS;
}

static char **aliases_infos(char **og, shell_t *shell)
{
    char **new = NULL;
    char **dest = NULL;

    if ((new = analyse_aliases(og[0], shell)))
        dest = concate_arrays(new, og + 1);
    new = NULL;
    while (dest && (new = analyse_aliases(dest[0], shell)) &&
        cmp_arrays(new, dest))
        dest = concate_arrays(new, dest + 1);
    if (!dest)
        return og;
    return dest;
}

char **apply_mods(char **og, shell_t *shell)
{
    char **dest = NULL;

    if (!og || !shell)
        return og;
    dest = ((dest = aliases_infos(og, shell)) ? dest : og);
    dest = ((dest = my_globbing(dest)) ? dest : og);
    return dest;
}
