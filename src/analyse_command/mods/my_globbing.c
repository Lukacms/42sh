/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_globbing
*/

#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

int globbing(char **tab, char *str)
{
    glob_t globb;
    int status = 0;
    char **tab = NULL;

    status = glob(str, GLOB_ERR, NULL, &globb);
    if (status != 0) {
        if (status == GLOB_NOMATCH)
            printf("no match");
        return 84;
    }
    printf("Found %zu filename matches\n",globb.gl_pathc);
    tab = globb.gl_pathv;
    str = concate_arrays(str, tab);
    globfree(&globb);
    return str;
}