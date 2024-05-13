/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %n
*/

#include "exec_specifier.h"
#include "spec_int_utils.h"
#include "buffer.h"

static void handle_cases(ptr_data_t data, void *ptr)
{
    int length = get_buffer_length(data.first_node);

    switch (data.length_mod[0]) {
        case 'h':
            if (data.length_mod[1] == 'h') {
                *(signed char *)ptr = length; break;
            } else {
                *(short int *)ptr = length; break;
            }
        case 'l':
            if (data.length_mod[1] == 'l') {
                *(long long int *)ptr = length; break;
            } else {
                *(long int *)ptr = length; break;
            }
        case 'j': *(intmax_t *)ptr = length; break;
        case 'z': *(size_t *)ptr = length; break;
        case 't': *(ptrdiff_t *)ptr = length; break;
        default: *(int *)ptr = length;
    }
}

char *compute_spec_n(void *ptr)
{
    ptr_data_t data = *((ptr_data_t *)ptr);
    void *temp = data.ptr;

    handle_cases(data, temp);

    return NULL;
}
