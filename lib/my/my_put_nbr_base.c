/*
** EPITECH PROJECT, 2021
** my_put_nbrbase.c
** File description:
** my_put_nbr_base
*/

#include "my.h"

int my_putnbr_base_unsigned_long(unsigned long nbr, char const *base)
{
    unsigned int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_base_unsign(nbr / len, base);
        my_putchar(base[nbr % len]);
        return (nbr);
    }
    return (nbr);
}

int my_putnbr_base_unsign(unsigned int nbr, char const *base)
{
    unsigned int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_base_unsign(nbr / len, base);
        my_putchar(base[nbr % len]);
        return (nbr);
    }
    my_putchar(base[nbr % len]);
    return nbr;
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr >= len) {
        my_putnbr_base(nbr / len, base);
        my_putchar(base[nbr % len]);
        return (nbr);
    }
    my_putchar(base[nbr % len]);
    return nbr;
}
