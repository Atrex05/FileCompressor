/*
** EPITECH PROJECT, 2022
** matric.c
** File description:
** matrix helper functions
*/

#include <stdarg.h>

#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_matrix.h"

mat_t *matrix_create(vec2i_t d)
{
    mat_t *mat = malloc(sizeof(mat_t));
    mat->m = malloc(sizeof(double *) * d.y);
    mat->x = d.x;
    mat->y = d.y;

    for (int i = 0; i < d.y; i++) {
        mat->m[i] = malloc(sizeof(double) * d.x);

        for (int j = 0; j < d.x; j++) {
            mat->m[i][j] = 0.0;
        }
    }

    return mat;
}

void matrix_print(mat_t *mat, int prec)
{
    for (int y = 0; y < mat->y; y++) {
        for (int x = 0; x < mat->x; x++) {
            my_printf("%s%.*f", (x != 0 ? "\t" : ""), prec, mat->m[y][x]);
        }

        my_printf("\n");
    }
}

void matrix_fill(mat_t *mat, ...)
{
    va_list ap;

    va_start(ap, mat);
    for (int i = 0; i < mat->y; i++) {
        for (int j = 0; j < mat->x; j++) {
            mat->m[i][j] = va_arg(ap, double);
        }
    }
    va_end(ap);
}

void matrix_free(mat_t *mat)
{
    for (int i = 0; i < mat->y; i++) {
        free(mat->m[i]);
    }

    free(mat->m);
    free(mat);
}
