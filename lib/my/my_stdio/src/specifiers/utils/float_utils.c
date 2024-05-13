/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for float specifiers
*/

#include "my_math.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "float_utils.h"
#include "str_operations.h"

static char *mult_exp(char *res, int exp)
{
    if (exp < 0) {
        exp *= -1;

        for (int i = 1; i <= exp; i++) {
            res = divide_str_2(res, 0);
        }
    } else {
        for (int i = 0; i < exp; i++) {
            res = multiply_str_2(res, 0);
        }
    }

    return res;
}

static char *null_double(char *res)
{
    res[(DOUBLE_PRECISION / 2) - 1] = '0';
    my_revstr(res);
    res[(DOUBLE_PRECISION / 2) + 1] = '\0';
    my_revstr(res);

    return res;
}

static char *not_null_double(
    char *res, int exp, int sign,
    inspector_t inspector
)
{
    char *pwr_2_str = my_memset(
        my_calloc((DOUBLE_PRECISION / 2) + 2, sizeof(char)), '0',
        (DOUBLE_PRECISION / 2) + 1);
    pwr_2_str[1] = '.';
    pwr_2_str[2] = '5';
    for (long mask = 0x8000000000000, i = 1; mask != 0; mask >>= 1, i++) {
        if (i > 1) pwr_2_str = divide_str_2(pwr_2_str, 2);
        if (inspector.bytes & mask)
            res = add_str(res, pwr_2_str);
    }
    if (exp != 0)
        res = mult_exp(res, exp);
    int idx = 0;
    do idx++; while (res[idx] == '0' && res[idx + 1] != '.');
    if (sign) res[idx - 1] = '-';
    my_revstr(res);
    res[DOUBLE_PRECISION - idx + sign] = '\0';
    my_revstr(res);
    free(pwr_2_str);
    return res;
}

char *compute_double(double nb)
{
    inspector_t inspector = {.nb = nb};
    int sign = (inspector.bytes >> 63) & 1;
    int exp = ((inspector.bytes & 0x7ff0000000000000) >> 52) - 1023;

    char *res = my_memset(
        my_calloc(DOUBLE_PRECISION + 1, sizeof(char)), '0', DOUBLE_PRECISION);
    res[(DOUBLE_PRECISION / 2) - 1] = '1';
    res[(DOUBLE_PRECISION / 2)] = '.';

    if (nb == 0.0) {
        res = null_double(res);
    } else {
        res = not_null_double(res, exp, sign, inspector);
    }

    return res;
}

char *handle_errors_float(double nb, int upper)
{
    int is_neg = (*(long *)&nb >> 63) & 1;
    char *err = NULL;

    if (isinf(nb) && is_neg)
        err = my_strdup(upper ? "-INF" : "-inf");

    if (isinf(nb) && !is_neg)
        err = my_strdup(upper ? "INF" : "inf");

    if (isnan(nb) && is_neg)
        err = my_strdup(upper ? "-NAN" : "-nan");

    if (isnan(nb) && !is_neg)
        err = my_strdup(upper ? "NAN" : "nan");

    return err;
}
