/*
** EPITECH PROJECT, 2022
** my_matrix
** File description:
** my_matrix declarations
*/

#ifndef INCLUDE_MY_MATRIX_
    #define INCLUDE_MY_MATRIX_
    #include "my_math.h"


typedef struct mat_s {
    int x;
    int y;
    double **m;
} mat_t;

mat_t *matrix_mult_k(mat_t *mat, double k);
mat_t *matrix_add(mat_t *m1, mat_t *m2);
mat_t *matrix_mult(mat_t *m1, mat_t *m2);
mat_t *matrix_create(vec2i_t d);
mat_t *matrix_dup(mat_t *mat);
mat_t *matrix_transpose(mat_t *mat);
mat_t *matrix_inverse(mat_t *mat);

void matrix_print(mat_t *mat, int prec);
void matrix_fill(mat_t *mat, ...);
void matrix_free(mat_t *mat);

double matrix_det(mat_t *mat);


#endif /* INCLUDE_MY_MATRIX_ */
