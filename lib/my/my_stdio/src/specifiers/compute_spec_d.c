/*
** EPITECH PROJECT, 2022
** specifier %d %i
** File description:
** specifier %d and %i
*/

#include "my_stdlib.h"
#include "spec_int_utils.h"

static void get_res(
    long long int verify, char *res,
    long long int nb, int i
)
{
    if (i == 1)
        res[0] = '-';

    while (verify > 0) {
        res[i] = (nb / verify) % 10 + '0';
        verify /= 10;
        i++;
    }
}

char *compute_spec_d(void *ptr)
{
    long long int nb = *((long long int *)ptr);
    int number_size = my_int_nbr_length(nb) + (nb == 0);
    long long int verify = 1;
    int i = 0;

    if (nb < 0) {
        number_size += 1;
        nb *= -1;
        i = 1;
    }

    char *res = my_calloc(number_size + 1, sizeof(char));
    while (nb / verify >= 10)
        verify *= 10;
    get_res(verify, res, nb, i);

    return res;
}
