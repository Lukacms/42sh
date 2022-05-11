/*
** EPITECH PROJECT, 2022
** my
** File description:
** load_file_in_mem
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat fstat;
    int status = -1;
    char *buffer = NULL;
    int fd = -1;

    if (!filepath)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) < 0)
        return NULL;
    if ((status = stat(filepath, &fstat)) < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (fstat.st_size + 1));
    if (!buffer)
        return NULL;
    if ((status = read(fd, buffer, fstat.st_size)) < 0)
        return NULL;
    buffer[status] = '\0';
    close(fd);
    return buffer;
}
