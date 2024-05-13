/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** round float utils
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "float_utils.h"
#include "post_processor.h"

static int get_value(char chr, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (chr == base[i]) {
            return i;
        }
    }

    return -1;
}

static void round_float_base(char **float_str, char const *base)
{
    int carry = 1;
    int tmp = 0;
    int base_len = my_strlen(base);
    int is_neg = (*float_str[0] == '-');
    for (int i = my_strlen(*float_str) - 1; i >= is_neg; i--) {
        if ((*float_str)[i] == 'x' || (*float_str)[i] == 'X') return;
        if ((*float_str)[i] == '.') continue;
        tmp = get_value((*float_str)[i], base) + carry;
        (*float_str)[i] = base[(tmp % base_len)];
        carry = tmp / base_len;
    }
    if (carry != 0) {
        char *new = my_calloc(my_strlen(*float_str) + is_neg + 2, sizeof(char));
        if (is_neg)
            new[0] = '-';
        new[is_neg] = base[carry];
        my_strcat(new, &((*float_str)[is_neg]));
        *float_str = new;
    }
}

void round_float(char **float_str, char next_chr, char spec)
{
    if (spec == 'e' || spec == 'E' || spec == 'f' ||
        spec == 'F' || spec == 'Z') {
        if (next_chr - '0' >= 5) {
            round_float_base(float_str, "0123456789");
        }
    }

    if (spec == 'a' || spec == 'A') {
        if (next_chr - '0' >= 7) {
            round_float_base(float_str, (spec == 'A') ?
                "0123456789ABCDEF" : "0123456789abcdef"
            );
        }
    }
}
