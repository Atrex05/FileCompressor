/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for the specifiers
*/

#include "my_str.h"

int my_int_nbr_length(long long int nb)
{
    int nb_digit = 0;

    while (nb) {
        nb = nb / 10;
        nb_digit++;
    }

    return nb_digit;
}

int my_uint_nbr_length(unsigned long long int nb)
{
    int nb_digit = 0;

    while (nb) {
        nb = nb / 10;
        nb_digit++;
    }

    return nb_digit;
}

int get_base_nbr_length(unsigned long long int nb, int base)
{
    int new_length = 0;

    while (nb != 0) {
        nb = nb / base;
        new_length++;
    }

    return new_length;
}

void compute_number(
    char *str, char const *base,
    unsigned long long int nb, int *utils
)
{
    int len = utils[0];
    int base_len = utils[1];

    while (nb != 0) {
        str[len] = base[nb % base_len];
        nb = nb / base_len;
        len--;
    }
}

void remove_useless_zeros(char *str)
{
    int i = my_strlen(str);
    int is_decimal = 0;

    for (int j = 0; j < i; j++)
        if (str[j] == '.')
            is_decimal = 1;
    if (!is_decimal)
        return;

    while (--i) {
        if (str[i] == '.') {
            str[i] = '\0';
            break;
        }
        if (str[i] != '0') {
            str[i + 1] = '\0';
            break;
        }
    }
}
