/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %x and %X
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "spec_int_utils.h"

static char *generic(unsigned long long int nb, const char *base)
{
    int base_len = my_strlen(base);
    int new_length = get_base_nbr_length(nb, base_len);
    int utils[] = { new_length - 1, base_len };
    char *str = my_calloc(new_length + 1, sizeof(char));

    compute_number(str, base, nb, utils);

    return str;
}

char *compute_spec_lo_x(void *ptr)
{
    unsigned long long int nb = *(unsigned long long int *)ptr;
    char const *base = "0123456789abcdef";

    return generic(nb, base);
}

char *compute_spec_up_x(void *ptr)
{
    unsigned long long int nb = *(unsigned long long int *)ptr;
    char const *base = "0123456789ABCDEF";

    return generic(nb, base);
}
