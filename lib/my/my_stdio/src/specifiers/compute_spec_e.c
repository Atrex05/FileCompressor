/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %e and %E
*/

#include "my_stdlib.h"
#include "float_utils.h"
#include "spec_e_utils.h"

static char *generic(double nb, int is_upper)
{
    char *res = my_memset(
        my_calloc(DOUBLE_PRECISION + 1, sizeof(char)), '0', DOUBLE_PRECISION);
    char *err = handle_errors_float(nb, 0);

    if (err != NULL) return err;

    char *double_str = compute_double(nb);
    int idx = 0;
    do idx++; while (double_str[idx] != '.');
    double_str[idx] = '\0';

    char *int_part = double_str;
    char *dec_part = &(double_str[idx + 1]);
    int utils[2] = { (int)(nb == 0.0), is_upper };

    convert_to_exp(res, int_part, dec_part, utils);

    return res;
}

char *compute_spec_lo_e(void *ptr)
{
    double nb = *((double *)ptr);

    return generic(nb, 0);
}

char *compute_spec_up_e(void *ptr)
{
    double nb = *((double *)ptr);

    return generic(nb, 1);
}
