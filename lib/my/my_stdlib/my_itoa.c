/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** converts a number to a string
*/

#include "my_stdlib.h"
#include "my_math.h"

char *my_itoa(long int nb)
{
    int is_neg = nb < 0;
    int len = my_nbr_length(nb) + is_neg;
    char *res = malloc(sizeof(char) * (len + 1));
    int i = len - 1;

    res[len] = '\0';
    nb = MY_ABS(nb);

    if (is_neg)
        res[0] = '-';
    if (nb == 0)
        res[i--] = '0';

    while (nb) {
        res[i--] = (nb % 10) + '0';
        nb /= 10;
    }

    return res;
}
