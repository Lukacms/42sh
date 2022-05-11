/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** displays N if integrer is negative, P if integrer is positive or null
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    my_putchar('\n');
    return (0);
}
