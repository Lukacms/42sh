/*
** EPITECH PROJECT, 2022
** my
** File description:
** free_array
*/

#include <stdlib.h>

void free_array(void **array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
