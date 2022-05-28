/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** getnextline
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include "mysh.h"
#include "my.h"

static int my_getc(termios_t term, size_t size)
{
    char buf[1] = {0};
    int isok = 0;

    if ((isok = read(STDIN_FILENO, buf, 1)) < 0 || buf[0] <= 0 ||
        (buf[0] == term.c_cc[VEOF] && !size))
        return EOF;
    return buf[0];
}

static void check_end(int i, char **ptr, size_t *n)
{
    if (i == END) {
        if (!((*ptr) = realloc((*ptr), (*n + 1))))
            return;
        ptr[0][*n] = '\n';
        (*n) += 1;
    }
}

ssize_t getshellline(shell_t *shell, char **ptr, size_t *n, FILE *stream)
{
    int i = 0;

    if (!ptr || !stream)
        return EOF;
    (*ptr) = malloc(sizeof(char));
    *ptr[0] = '\0';
    while ((i = my_getc(shell->termios, *n)) != END && i != EOF) {
        if (analyse_char(i, shell) == SUCCESS)
            continue;
        *n += 1;
        if (!((*ptr) = realloc((*ptr), (*n))))
            return FAILURE;
        ptr[0][*n - 1] = i;
    }
    if (i == EOF) {
        (*ptr) = NULL;
        return EOF;
    }
    check_end(i, ptr, n);
    return (*n);
}
