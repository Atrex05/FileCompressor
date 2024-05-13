/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** extractors for post_processor
*/

#include <stddef.h>

#include "my_str.h"

void extract_a_p_hex(char *new_res, char *res, char spec, int show_sign)
{
    if ((my_strlen(new_res) > my_strlen(res)) &&
        (spec == 'a' || spec == 'A') &&
        new_res[0] != ' ') {
        new_res[0] = res[0];
        new_res[1] = res[1];
        res[1] = '0';
    }

    int i = show_sign;
    if (spec == 'p') {
        new_res[i++] = '0';
        new_res[i++] = 'x';
    }
}

char *extract_exp(char *float_str)
{
    for (int i = 0; float_str[i + 1] != '\0'; i++) {
        if ((float_str[i] == 'e' || float_str[i] == 'p' ||
            float_str[i] == 'E' || float_str[i] == 'P') &&
            (float_str[i + 1] == '-' || float_str[i + 1] == '+')) {
            char *new = my_strdup(&(float_str[i]));
            float_str[i] = '\0';

            return new;
        }
    }

    return NULL;
}
