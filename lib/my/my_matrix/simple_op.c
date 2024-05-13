/*
** EPITECH PROJECT, 2022
** my_matrix
** File description:
** matrix simple operations
*/

#include "my_stdlib.h"
#include "my_matrix.h"

mat_t *matrix_add(mat_t *m1, mat_t *m2)
{
    if (m1->x != m2->x || m1->y != m2->y) {
        return NULL;
    }

    mat_t *mat = malloc(sizeof(mat_t));
    mat->m = malloc(sizeof(double *) * m1->y);
    mat->x = m1->x;
    mat->y = m1->y;

    for (int i = 0; i < mat->y; i++) {
        mat->m[i] = malloc(sizeof(double) * mat->x);

        for (int j = 0; j < mat->x; j++) {
            mat->m[i][j] = m1->m[i][j] + m2->m[i][j];
        }
    }

    return mat;
}

static void mult_helper(mat_t *mat, mat_t *m1, mat_t *m2, int i)
{
    for (int j = 0; j < mat->x; j++) {
        mat->m[i][j] = 0.0;

        for (int k = 0; k < m1->x; k++) {
            mat->m[i][j] += m1->m[i][k] * m2->m[k][j];
        }
    }
}

mat_t *matrix_mult(mat_t *m1, mat_t *m2)
{
    if (m1->x != m2->y) {
        return NULL;
    }

    mat_t *mat = malloc(sizeof(mat_t));
    mat->m = malloc(sizeof(double *) * m1->y);
    mat->x = m2->x;
    mat->y = m1->y;

    for (int i = 0; i < mat->y; i++) {
        mat->m[i] = malloc(sizeof(double) * mat->x);

        for (int j = 0; j < mat->x; j++) {
            mat->m[i][j] = 0.0;
            mult_helper(mat, m1, m2, i);
        }
    }

    return mat;
}

mat_t *matrix_mult_k(mat_t *m, double k)
{
    mat_t *mat = malloc(sizeof(mat_t));
    mat->m = malloc(sizeof(double *) * m->y);
    mat->x = m->x;
    mat->y = m->y;

    for (int i = 0; i < mat->y; i++) {
        mat->m[i] = malloc(sizeof(double) * mat->x);

        for (int j = 0; j < mat->x; j++) {
            mat->m[i][j] = m->m[i][j] * k;
        }
    }

    return mat;
}
