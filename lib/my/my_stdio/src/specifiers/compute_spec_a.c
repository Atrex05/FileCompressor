/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %a and %A
*/

#include "my_stdlib.h"
#include "spec_a_utils.h"

static char *generic(double nb, int is_upper, char const *base)
{
    int MAX_SIZE = 25;
    char *res = my_calloc(MAX_SIZE, sizeof(char));
    inspector_t inspector = {.nb = nb};

    my_specifier_a_helper(res, inspector, is_upper, base);

    return res;
}

char *compute_spec_lo_a(void *ptr)
{
    double nb = *((double *)ptr);
    char const *base = "0123456789abcdef";

    return generic(nb, 0, base);
}

char *compute_spec_up_a(void *ptr)
{
    double nb = *((double *)ptr);
    char const *base = "0123456789ABCDEF";

    return generic(nb, 1, base);
}
