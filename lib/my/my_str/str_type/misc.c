/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include <unistd.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

str_t **str_clear(str_t **str)
{
    my_memset((*str)->data, 0, sizeof(char) * (*str)->capacity);
    (*str)->length = 0;

    return str;
}

str_t **str_resize(str_t **str, size_t new_len)
{
    size_t new_cap = get_padded_size(new_len);
    str_t *old = *str;
    *str = malloc(sizeof(str_t) + sizeof(char) * new_cap);

    my_memcpy((*str)->data, old->data, old->length);
    (*str)->length = old->length;
    (*str)->capacity = new_cap;
    free(old);

    return str;
}

void str_print(str_t *str)
{
    write(1, str->data, str->length);
}
