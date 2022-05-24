/*
** EPITECH PROJECT, 2022
** array_len
** File description:
** array_len
*/

int array_len(char **array)
{
    int i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}
