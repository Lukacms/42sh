/*
** EPITECH PROJECT, 2021
** my_putaddr.c
** File description:
** display a pointer's address
*/

#include "my.h"

void my_putaddr(unsigned long addr)
{
    if (addr == 0)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_putnbr_base_unsigned_long(addr, "0123456789abcdef");
    }
}
