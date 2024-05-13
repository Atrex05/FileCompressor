/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** misc
*/

#include "my_vec.h"

size_t get_padded_size(size_t size)
{
    size_t size_pad = 1;

    while (size_pad < size)
        size_pad *= 2;

    return size_pad;
}

void vec_swap(vec_t *v, size_t i, size_t j)
{
    static char temp[MAX_VEC_ELEM_SIZE] = {0};
    size_t el_size = v->base.el_size;

    my_memcpy(temp, v->data + (el_size * i), el_size);
    my_memcpy(v->data + (el_size * i), v->data + (el_size * j), el_size);
    my_memcpy(v->data + (el_size * j), temp, el_size);
}
