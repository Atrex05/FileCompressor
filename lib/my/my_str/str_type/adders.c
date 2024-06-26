/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string setters
*/

#include <stdarg.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

str_t **str_add(str_t **str, char const *new)
{
    size_t new_len = my_strlen(new);

    if ((*str)->length + new_len > (*str)->capacity)
        str_resize(str, (*str)->length + new_len);

    my_memcpy((*str)->data + (*str)->length, new, new_len);
    (*str)->length += new_len;

    return str;
}

str_t **str_stradd(str_t **str, str_t const *new)
{
    if ((*str)->length + new->length > (*str)->capacity)
        str_resize(str, (*str)->length + new->length);

    my_memcpy((*str)->data + (*str)->length, new->data, new->length);
    (*str)->length += new->length;

    return str;
}

str_t **str_cadd(str_t **str, char const new)
{
    if ((*str)->length + 1 > (*str)->capacity)
        str_resize(str, (*str)->length + 1);

    (*str)->data[(*str)->length] = new;
    (*str)->length++;

    return str;
}

str_t **str_vadd(str_t **str, int argc, ...)
{
    va_list ap;

    va_start(ap, argc);
    while (argc--)
        str_add(str, va_arg(ap, char *));
    va_end(ap);

    return str;
}

str_t **str_nadd(str_t **str, char const *new, size_t n)
{
    if ((*str)->length + n > (*str)->capacity)
        str_resize(str, (*str)->length + n);

    my_memcpy((*str)->data + (*str)->length, new, n);
    (*str)->length += n;

    return str;
}
