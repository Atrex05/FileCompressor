/*
** EPITECH PROJECT, 2022
** specifier %u
** File description:
** specifier %u
*/

#include "my_stdlib.h"
#include "spec_int_utils.h"

static void get_res(long long int verify, char *res, long long int nb, int i)
{
    while (verify > 0) {
        res[i] = (nb / verify) % 10 + '0';
        verify /= 10;
        i++;
    }
}

char *compute_spec_u(void *ptr)
{
    unsigned long long int nb = *(unsigned long long int *)ptr;
    int number_size = my_uint_nbr_length(nb);
    unsigned long long int verify = 1;
    int i = 0;

    char *res = my_calloc('\0', sizeof(char) * (number_size + 1));
    while (nb / verify >= 10)
        verify *= 10;
    get_res(verify, res, nb, i);

    return res;
}
