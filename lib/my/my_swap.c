/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** task01
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
