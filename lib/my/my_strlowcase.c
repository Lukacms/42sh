/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** task09d06
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
        else
            str[i] = str[i];
    }
    return str;
}
