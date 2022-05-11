/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** task05
*/

static int my_strlen2(char const *str)
{
    int a = 0;

    while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9') {
        a = a + 1;
    }
    return (a);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int s = 1;
    long n = 0;

    if (my_strlen2(str) > 10)
        return (0);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            s = s * -1;
        i = i + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        n = (n * 10) + (str[i] - 48);
        i = i + 1;
    }
    n = n * s;
    if (n < -2147483648 || n > 2147483647)
        return (0);
    return (n);
}
