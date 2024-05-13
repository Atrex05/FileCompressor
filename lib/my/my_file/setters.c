/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file setters
*/

#include <fcntl.h>
#include <stdarg.h>

#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_file.h"

void file_write(file_t *file, char *str)
{
    write(file->fd, str, my_strlen(str));
}

void file_fwrite(file_t *file, char *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    file_write(file, dest);

    free(dest);
}
