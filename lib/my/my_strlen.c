/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
