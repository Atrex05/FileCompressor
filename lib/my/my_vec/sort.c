/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vec sort
*/

#include "my_stdlib.h"
#include "my_vec.h"

static int default_compare(vec_t *v, size_t i, size_t pivot)
{
    return (((vec_int_t*)v)->data[i] < ((vec_int_t*)v)->data[pivot]);
}

static int partition(
    vec_t *v, int (*cmp_fn)(vec_t *, size_t, size_t),
    int start, int end
)
{
    int pivot = end;
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (cmp_fn(v, j, pivot) <= 0) {
            i++;
            vec_swap(v, i, j);
        }
    }
    i++;
    vec_swap(v, i, end);

    return i;
}

static void quick_sort(
    vec_t *v, int (*cmp_fn)(vec_t *, size_t, size_t),
    int start, int end
)
{
    if (start >= end)
        return;

    int center = partition(v, cmp_fn, start, end);

    quick_sort(v, cmp_fn, start, center - 1);
    quick_sort(v, cmp_fn, center + 1, end);
}

void vec_sort(vec_t *vec, int (*cmp_fn)(vec_t *, size_t, size_t))
{
    if (cmp_fn == NULL)
        cmp_fn = &default_compare;

    quick_sort(vec, cmp_fn, 0, vec->base.size - 1);
}
