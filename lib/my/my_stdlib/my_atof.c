/*
** EPITECH PROJECT, 2022
** my_atof
** File description:
** atof clone
*/

#include "my_str.h"

double my_atof(char const *str)
{
    double sign = 1;
    double nb = 0;
    double offset = 1;
    int found_dot = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str != '\0' && (my_isnum(*str) || (*str == '.' && !found_dot))) {
        if (*str == '.') {
            found_dot = 1;
        } else {
            nb = nb * 10 + (*str - '0');
            offset *= ((found_dot) ? 10 : 1);
        }
        str++;
    }
    return sign * (nb / offset);
}
