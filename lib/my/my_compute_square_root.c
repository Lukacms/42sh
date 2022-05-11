/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task05d05
*/

int my_compute_square_root(int nb)
{
    int r = 0;

    if (nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    else {
        while (r * r != nb && r != nb)
            r = r + 1;
    }
    if (r == nb)
        return 0;
    return r;
}
