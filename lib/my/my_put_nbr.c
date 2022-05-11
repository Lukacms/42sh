/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** task07
*/

#include <unistd.h>

void my_putchar(char c);

static void my_put_nbrbis(int nb, int d)
{
    while (d > 1) {
        my_putchar((nb / d) + 48);
        nb = nb % d;
        d = d / 10;
    }
    my_putchar(nb + 48);
}

int my_put_nbr(int nb)
{
    int i = nb;
    int d = 1;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    } else if (nb < 0 && nb > -2147483648) {
        my_putchar('-');
        nb = nb * (-1);
        i = i * (-1);
    }
    while (i >= 10) {
        i = i / 10;
        d = d * 10;
    }
    my_put_nbrbis(nb, d);
    return (0);
}
