/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** char_in_str
*/

int char_in_str(char *str, char c)
{
    if (!str)
        return 0;
    for (unsigned int i = 0; str[i]; i += 1)
        if (str[i] == c)
            return 1;
    return 0;
}
