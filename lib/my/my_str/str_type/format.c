/*
** EPITECH PROJECT, 2022
** antman
** File description:
** format utils
*/

#include <stdarg.h>

#include "my_stdio.h"
#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    str_add(str, dest);

    free(dest);

    return str;
}

str_t **str_slice(str_t **str, size_t start, size_t end)
{
    for (size_t i = 0; i < end - start; i++)
        (*str)->data[i] = (*str)->data[start + i];

    (*str)->length = end - start;

    return str;
}
