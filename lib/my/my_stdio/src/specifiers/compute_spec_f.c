/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier lofloat %f
*/

#include "my_stdlib.h"
#include "float_utils.h"

static char *generic(double nb, int is_upper)
{
    char *err = handle_errors_float(nb, is_upper);

    if (err != NULL) return err;

    char *res = compute_double(nb);

    return res;
}

char *compute_spec_lo_f(void *ptr)
{
    double nb = *((double *)ptr);

    return generic(nb, 0);
}

char *compute_spec_up_f(void *ptr)
{
    double nb = *((double *)ptr);

    return generic(nb, 1);
}
