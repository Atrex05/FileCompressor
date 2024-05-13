/*
** EPITECH PROJECT, 2022
** my_matrix
** File description:
** compute matrix det
*/

#include "my_matrix.h"

static void det_normalize(mat_t *mat, double pivot, int col, int pivot_line)
{
    double pivot_ = 0.0;

    for (int j = 0; j < mat->y; j++) {
        if (j <= pivot_line) continue;

        pivot_ = mat->m[j][col];

        for (int i = 0; i < mat->x; i++) {
            mat->m[j][i] -= (mat->m[pivot_line][i] / pivot) * pivot_;
        }
    }
}

double matrix_det(mat_t *mat)
{
    int pivot_line = 0;
    double pivot = 0.0;
    double det = 1.0;

    for (int col = 0; col < mat->x; col++) {
        pivot_line = col;
        pivot = mat->m[pivot_line][col];
        if (pivot == 0.0)
            pivot = 1.0;
        det_normalize(mat, pivot, col, pivot_line);
    }

    for (int i = 0; i < mat->x; i++)
        det *= mat->m[i][i];

    return det;
}
