/*
** EPITECH PROJECT, 2021
** concat_params.c
** File description:
** task02d08
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    char *str = NULL;
    int count = 0;
    int total = 0;

    for (int i = 0; i < argc; i += 1)
        total += my_strlen(argv[i]);
    str = malloc(sizeof(char) * (total + argc + 1));
    for (int i = 0; i < argc; i += 1) {
        for (int j = 0; argv[i][j] != '\0'; j += 1)
            str[count] = argv[i][j];
        str[count] = '\n';
        count += 1;
    }
    str[total + argc] = '\0';
    return str;
}
