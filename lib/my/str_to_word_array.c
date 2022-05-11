/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** src_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static int is_delim(char c , char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return 1;
    return 0;
}

static int count_words(char *src, char *delim)
{
    int nb = 0;

    if (!is_delim(src[0], delim))
        nb++;
    for (int i = 1; src[i]; i++) {
        if (!is_delim(src[i], delim) && is_delim(src[i - 1], delim))
            nb++;
    }
    return nb;
}

char **str_to_array_choice(char *src, char *delim)
{
    char **array = NULL;
    int nb_words = 0;
    int i = 0;
    int j = 0;

    if (!src || !delim || (nb_words = count_words(src, delim)) <= 0)
        return NULL;
    if (!(array = malloc(sizeof(char *) * (nb_words + 1))))
        return NULL;
    for (int nb = 0; nb < nb_words; nb++) {
        for (i = j; src[i] && is_delim(src[i], delim); i = i + 1);
        for (j = i; src[j] && !is_delim(src[j], delim); j = j + 1);
        if (!(array[nb] = my_strndup(src + i, j - i)))
            return NULL;
    }
    array[nb_words] = NULL;
    return array;
}
