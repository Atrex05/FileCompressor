/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for exp modifiers
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "float_utils.h"
#include "spec_e_utils.h"

void convert_to_exp(
    char *res, char *int_part,
    char *float_part, int *utils
)
{
    int is_null = utils[0];
    int is_upper = utils[1];

    if (is_null) {
        convert_0_to_exp(res, float_part, is_upper);
        return;
    }

    if (int_part[0] == '0' || (int_part[0] == '-' && int_part[1] == '0')) {
        convert_dec_to_exp(res, int_part, float_part, is_upper);
    } else {
        convert_int_to_exp(res, int_part, float_part, is_upper);
    }
}

void convert_int_to_exp(
    char *res, char *int_part,
    char *float_part, int is_up
)
{
    int i = 0;
    int pow_10 = my_strlen(int_part) - 1 - (int_part[0] == '-');

    res[i++] = int_part[0];
    if (int_part[0] == '-') res[i++] = int_part[1];
    res[i++] = '.';

    for (; int_part[i - 1] != '\0'; i++) {
        res[i] = int_part[i - 1];
    }

    for (int j = 0; res[i] != '\0'; j++, i++) {
        res[i] = float_part[j];
    }

    add_exponent(res, '+', pow_10, is_up);
}

void convert_0_to_exp(char *res, char *float_part, int is_upper)
{
    res[0] = '0';
    res[1] = '.';

    for (int i = 2; res[i] != '\0'; i++)
        res[i] = float_part[i - 2];

    add_exponent(res, '+', 0, is_upper);
}

void convert_dec_to_exp(
    char *res, char *int_part,
    char *float_part, int is_upper
)
{
    int i = 0;
    int pow_10 = 0;

    while (float_part[i] == '0') i++;
    pow_10 = i + 1;

    if (int_part[0] == '-') res[0] = '-';
    res[(int_part[0] == '-')] = float_part[i++];
    res[(int_part[0] == '-') + 1] = '.';

    for (int idx = 2 + (int_part[0] == '-'); res[idx] != '\0'; idx++) {
        res[idx] = float_part[i];
        i++;
    }

    add_exponent(res, '-', pow_10, is_upper);
}

void add_exponent(char *res, char sign, int pow_10, int is_upper)
{
    my_revstr(res);
    char *pow_10_str = my_itoa(pow_10);
    int pow_len = my_strlen(pow_10_str) - 1;
    res[pow_len + 2 + (pow_len == 0)] = is_upper ? 'E' : 'e';
    res[pow_len + 1 + (pow_len == 0)] = sign;

    if (pow_len == 0)
        res[pow_len + 1] = '0';

    for (int i = 0; i <= pow_len; i++) {
        res[pow_len - i] = pow_10_str[i];
    }

    my_revstr(res);
}
