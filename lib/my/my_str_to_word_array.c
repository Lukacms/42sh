/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** task04d09
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

static int my_isalphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

static int count_words(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) == 1 && my_isalphanum(str[i - 1]) != 1)
            n++;
    }
    return (n);
}

static char *get_new_word(char const *str, int i, int j)
{
    int word_length = j - i;
    char *new_word = NULL;

    new_word = malloc(sizeof(char) * (word_length + 1));
    my_strncpy(new_word, str + i, word_length);
    return (new_word);
}

char **my_str_to_word_array(char const *str)
{
    int nb_words = 0;
    int j = 0;
    int i = 0;
    char **array = NULL;

    if (str == NULL)
        return (NULL);
    nb_words = count_words(str);
    array = malloc(sizeof(char *) * (nb_words + 1));
    for (int word_i = 0; word_i < nb_words; word_i++) {
        for (i = j; !my_isalphanum(str[i]); i = i + 1);
        for (j = i; my_isalphanum(str[j]); j = j + 1);
        array[word_i] = get_new_word(str, i, j);
    }
    array[nb_words] = NULL;
    return (array);
}
