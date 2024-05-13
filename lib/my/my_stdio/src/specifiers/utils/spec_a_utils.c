/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %a
*/

#include <stdio.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "float_utils.h"
#include "spec_a_utils.h"

void my_specifier_a_helper(
    char *res, inspector_t inspector,
    int is_upp, char const *base
)
{
    int sign = (inspector.bytes >> 63) & 1;
    int exp = ((inspector.bytes & 0x7ff0000000000000) >> 52) - 1023;
    int idx = 0;

    if (sign)
        res[idx++] = '-';
    res[idx++] = '0';
    res[idx++] = is_upp ? 'X' : 'x';
    res[idx++] = '1';
    res[idx++] = '.';

    for (long mask = 0xf000000000000, offset = 48;
        mask != 0; mask >>= 4, offset -= 4) {
        res[idx++] = base[(unsigned char)((inspector.bytes & mask) >> offset)];
    }

    res[idx++] = is_upp ? 'P' : 'p';
    if (exp >= 0) res[idx] = '+';
    my_strcat(res, my_itoa(exp));
}
