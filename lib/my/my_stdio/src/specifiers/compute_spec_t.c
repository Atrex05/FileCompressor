/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %T
*/

#include "my_math.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "exec_specifier.h"

static const int INT_ARR_END = -1;
static const char INT_ARR_CHAR_END[] = " - ";

static void add_int_arr_to_str(char *res, int *nb)
{
    int started = 0;

    while (*nb != INT_ARR_END) {
        if (started) {
            my_strcat(res, INT_ARR_CHAR_END);
        } else {
            started = 1;
        }
        my_strcat(res, my_itoa(*nb));
        nb++;
    }
}

static int get_int_arr_length(int *nb, int end)
{
    int len = 0;

    while (*nb != end) {
        len += my_nbr_length(*nb);
        len += my_strlen(INT_ARR_CHAR_END);
        nb++;
    }

    return len;
}

char *compute_spec_t(void *ptr)
{
    ptr_data_t data = *((ptr_data_t *)ptr);
    int *nb = (int *)data.ptr;
    int len = get_int_arr_length(nb, INT_ARR_END);
    char *res = my_calloc(len + 1, sizeof(char));

    add_int_arr_to_str(res, nb);

    return res;
}
