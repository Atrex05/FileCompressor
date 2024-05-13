/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** setters
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_resize(vec_t **vec, size_t new_size)
{
    vec_t *old = *vec;
    *vec = vec_create(new_size, old->base.el_size);

    my_memcpy((*vec)->data, old->data, old->base.size * old->base.el_size);
    (*vec)->base.size = old->base.size;

    free(old);
}

void vec_remove(vec_t *vec, size_t idx)
{
    my_memset(vec->data + idx * vec->base.el_size, 0, vec->base.el_size);
    vec->base.size--;
}

void vec_insert(vec_t **vec, void *elem, size_t idx)
{
    if (idx >= (*vec)->base.capacity)
        vec_resize(vec, idx + 1);

    my_memcpy(
        (*vec)->data + idx * (*vec)->base.el_size,
        elem, (*vec)->base.el_size
    );
    (*vec)->base.size++;
}

void vec_clear(vec_t *vec)
{
    my_memset(vec->data, 0, vec->base.size * vec->base.el_size);
    vec->base.size = 0;
}

void vec_push_back(vec_t **vec, void *elem)
{
    size_t size = (*vec)->base.size;
    size_t el_size = (*vec)->base.el_size;

    if (size + 1 >= (*vec)->base.capacity)
        vec_resize(vec, size + 1);

    my_memcpy((*vec)->data + size * el_size, elem, el_size);
    (*vec)->base.size++;
}
