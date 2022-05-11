/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** task12d06
*/

int my_str_isalpha(char const *str)
{
    if (!str || str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
        else
            return 0;
    }
    return 1;
}
