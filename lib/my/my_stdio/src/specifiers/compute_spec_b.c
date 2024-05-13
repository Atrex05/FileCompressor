/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %b
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "spec_int_utils.h"

char *compute_spec_b(void *ptr)
{
    unsigned long long int bin = *(unsigned long long int *)ptr;
    char const *base = "01";

    int base_len = my_strlen(base);
    int new_length = get_base_nbr_length(bin, base_len);
    int utils[] = { new_length - 1, base_len };
    char *str = my_calloc(new_length + 1, sizeof(char));

    compute_number(str, base, bin, utils);

    return str;
}
