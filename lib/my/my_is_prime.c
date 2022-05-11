/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** task06d05
*/

int my_is_prime(int nb)
{
    int d = 11;

    if (nb == 0 || nb == 1)
        return (0);
    if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11)
        return (1);
    if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
        return (0);
    while (d <= nb / 2) {
        if (nb % d == 0)
            return (0);
        d = d + 2;
    }
    return (1);
}
