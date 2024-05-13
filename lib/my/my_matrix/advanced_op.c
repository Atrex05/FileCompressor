/*
** EPITECH PROJECT, 2022
** my_matrix
** File description:
** matrix advanced operations
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_matrix.h"

mat_t *matrix_transpose(mat_t *mat)
{
    mat_t *transp = matrix_create((vec2i_t){.x = mat->y, .y = mat->x});

    for (int i = 0; i < transp->y; i++) {
        for (int j = 0; j < transp->x; j++) {
            transp->m[i][j] = mat->m[j][i];
        }
    }

    return transp;
}

mat_t *matrix_dup(mat_t *mat)
{
    mat_t *copy = matrix_create((vec2i_t){.x = mat->x, .y = mat->y});

    for (int y = 0; y < mat->y; y++)
        for (int x = 0; x < mat->x; x++)
            copy->m[y][x] = mat->m[y][x];

    return copy;
}
