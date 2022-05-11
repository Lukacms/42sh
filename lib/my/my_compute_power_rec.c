/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** task04d05
*/

int my_compute_power_rec(int nb, int p)
{
    int r = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    else
        r = r * my_compute_power_rec(nb, p - 1);
    return r;
}
