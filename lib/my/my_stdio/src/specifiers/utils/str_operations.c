/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** helper for str operations
*/

#include "my_str.h"

char *add_str(char *res, char *add)
{
    my_revstr(res);
    my_revstr(add);
    int nb1 = 0;
    int nb2 = 0;
    int acc = 0;
    int carry = 0;

    for (int i = 0; add[i] != '\0' && res[i] != '\0'; i++) {
        if (res[i] == '.') continue;
        nb1 = res[i] - '0';
        nb2 = add[i] - '0';
        acc = nb1 + nb2 + carry;
        res[i] = (acc % 10)+ '0';
        carry = acc / 10;
    }
    my_revstr(res);
    my_revstr(add);

    return res;
}

char *multiply_str_2(char *last_pow, int last_idx)
{
    int carry = 0;
    my_revstr(last_pow);

    while (last_pow[last_idx] != '\0') {
        if (last_pow[last_idx] == '.') {
            last_idx++;
            continue;
        }

        int digit = (last_pow[last_idx] - '0') * 2 + carry;
        last_pow[last_idx] = (digit % 10) + '0';
        carry = digit / 10;
        last_idx++;
    }

    my_revstr(last_pow);
    return last_pow;
}

char *divide_str_2(char *last_pow, int last_idx)
{
    int carry = 0;

    while (last_pow[last_idx] != '\0') {
        if (last_pow[last_idx] == '.') {
            last_idx++;
            continue;
        }

        int digit = (last_pow[last_idx] - '0') + carry * 10;
        last_pow[last_idx] = (digit / 2) + '0';
        carry = digit % 2;
        last_idx++;
    }

    return last_pow;
}
