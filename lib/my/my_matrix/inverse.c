/*
** EPITECH PROJECT, 2022
** my_matrix
** File description:
** inverse square matrix
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_matrix.h"

static mat_t *matrix_augment(mat_t *mat)
{
    mat_t *aug_mat = matrix_create((vec2i_t){.x = 2.0 * mat->x,.y = mat->y});
    int start_x = mat->x;

    for (int y = 0; y < mat->y; y++, start_x++) {
        aug_mat->m[y][start_x] = 1.0;
        for (int x = 0; x < mat->x; x++)
            aug_mat->m[y][x] = mat->m[y][x];
    }

    return aug_mat;
}

static void gauss_normalize(mat_t *mat, int col, int pivot_line)
{
    double pivot = 0.0;

    for (int j = 0; j < mat->y; j++) {
        if (j == pivot_line) continue;

        pivot = mat->m[j][col];

        for (int i = 0; i < mat->x; i++) {
            mat->m[j][i] -= mat->m[pivot_line][i] * pivot;
        }
    }
}

static void gauss_pivoting(mat_t *mat)
{
    int pivot_line = 0;
    double pivot = 0.0;

    for (int col = 0; col < mat->x / 2; col++) {
        pivot_line = col;
        pivot = mat->m[pivot_line][col];
        if (pivot == 0.0)
            pivot = 1.0;

        for (int i = 0; i < mat->x; i++)
            mat->m[pivot_line][i] /= pivot;

        gauss_normalize(mat, col, pivot_line);
    }
}

mat_t *matrix_inverse(mat_t *mat)
{
    mat_t *aug_mat = matrix_augment(mat);
    mat_t *inverse = matrix_create((vec2i_t){.x = mat->x, .y = mat->y});

    gauss_pivoting(aug_mat);

    for (int y = 0; y < aug_mat->y; y++)
        for (int x = 0; x < aug_mat->x / 2; x++)
            inverse->m[y][x] = aug_mat->m[y][aug_mat->x / 2 + x];

    matrix_free(aug_mat);

    return inverse;
}
