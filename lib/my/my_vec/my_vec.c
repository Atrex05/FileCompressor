/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#include "my_stdlib.h"
#include "my_vec.h"

vec_t *vec_create(size_t nb_data, size_t el_size)
{
    if (el_size > MAX_VEC_ELEM_SIZE)
        return NULL;

    size_t capacity = get_padded_size(nb_data);
    vec_t *vec = malloc(sizeof(vec_t) + el_size * capacity);

    if (vec == NULL)
        return NULL;

    vec->base.size = 0;
    vec->base.el_size = el_size;
    vec->base.capacity = capacity;

    return vec;
}

void vec_free(vec_t *vec, void (*free_fn)(void*))
{
    vec_void_t *vec_void = (vec_void_t*)vec;

    for (size_t i = 0; i < vec->base.size; i++)
        free_fn(vec_void->data[i]);

    free(vec);
}
