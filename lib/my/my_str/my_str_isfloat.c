/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** returns 1 if every chars of the string is digit
*/

#include "my_str.h"

int my_str_isfloat(char const *str)
{
    if (str[0] == '\0')
        return 1;

    int float_pt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!my_isnum(str[i]) && str[i] != '.')
            return 0;
        if (str[i] == '.')
            float_pt++;
    }

    return (float_pt <= 1);
}
