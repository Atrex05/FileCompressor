/*
** EPITECH PROJECT, 2022
** my_atoi.c
** File description:
** returns a number from a string
*/

#include "my_str.h"

int my_atoi(char const *str)
{
    int nb = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0' && my_isnum(*str)) {
        nb = nb * 10 + (*str - '0');
        str++;
    }

    return nb * sign;
}
