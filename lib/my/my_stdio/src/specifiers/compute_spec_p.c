/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %p
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "exec_specifier.h"
#include "spec_int_utils.h"

char *compute_spec_p(void *ptr)
{
    ptr_data_t data = *((ptr_data_t *)ptr);
    unsigned long int temp = (intptr_t)data.ptr;
    char const *base = "0123456789abcdef";

    int base_len = my_strlen(base);
    int new_length = get_base_nbr_length(temp, base_len);
    int utils[] = { new_length - 1, base_len };
    char *str = my_calloc(new_length + 1, sizeof(char));

    compute_number(str, base, temp, utils);

    return str;
}
