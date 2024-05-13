/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** post processor for the specifiers output
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "state.h"
#include "post_processor.h"
#include "float_utils.h"
#include "spec_int_utils.h"

static char *parse_float_util(
    char **new_res, char *float_str,
    int precision, parse_state_t *state
)
{
    int i = 0;
    char *exp = extract_exp(float_str);
    while (float_str[i] != '\0' && float_str[i] != '.') i++;
    if (float_str[i] == '\0') return float_str;
    my_strcat(*new_res, float_str);
    (*new_res)[my_strlen(*new_res)] = '0';
    char next_chr = (*new_res)[i + precision +
        ((*new_res)[i + precision + 1] != '.')];
    (*new_res)[i + precision + (precision != 0)] = '\0';
    round_float(new_res, next_chr, state->specifier);
    if (((state->specifier == 'a' || state->specifier == 'A') &&
        state->precision == DOUBLE_PRECISION) ||
        state->specifier == 'Z')
        remove_useless_zeros(*new_res);
    if (exp != NULL) {
        (*new_res)[my_strlen(*new_res)] = '\0';
        my_strcat(*new_res, exp);
    }
    return NULL;
}

char *post_processor_float(char *float_str, parse_state_t *state)
{
    if ((state->specifier == 'a' || state->specifier == 'A') &&
        state->precision == 0) state->precision = DOUBLE_PRECISION;
    int precision = state->precision == -2 ? 0 :
        (state->precision == 0 ? 6 : state->precision);
    int size = DOUBLE_PRECISION + (precision > 0 ? precision : 0);
    char *new_res = my_memset(my_calloc(size + 1, sizeof(char)), '0', size);
    new_res[0] = '\0';
    char *temp = parse_float_util(&new_res, float_str, precision, state);
    if (temp != NULL) return temp;
    int sign_space = state->flags.show_sign ||
        state->flags.space_if_pos || float_str[0] == '-';
    int new_size = (my_strlen(new_res) > (size_t)state->width ?
        my_strlen(new_res) : (size_t)state->width) + sign_space;
    char *padded_res = my_calloc(new_size + 1, sizeof(char));
    int utils[3] = { sign_space, new_size, float_str[0] == '-' };
    apply_alignment(new_res, padded_res, utils, state);
    free(new_res);
    free(float_str);
    return padded_res;
}

char *post_processor_str(char *str, parse_state_t *state)
{
    int new_size = my_strlen(str) > (size_t)state->width ?
        my_strlen(str) : (size_t)state->width;
    if (state->width == 0 && state->precision > 0 &&
        (size_t)state->precision < my_strlen(str))
        new_size = state->precision;
    char *new_res = my_memset(my_calloc(new_size + 1, 1), ' ', new_size);
    new_res[new_size] = '\0';
    if (state->precision == -2 && state->specifier != 'c')
        return my_strdup("");
    if (state->precision != 0 && state->specifier != 'c')
        for (int i = 0; str[i] != '\0'; i++)
            str[i] = (i >= state->precision) ? '\0' : str[i];
    if (state->width != 0 && !state->flags.align_left)
        my_revstr(str);
    for (int i = 0; str[i] != '\0'; i++)
        new_res[i] = str[i];
    if (state->width != 0 && !state->flags.align_left)
        my_revstr(new_res);
    free(str);
    return new_res;
}

char *post_processor_int(char *res, parse_state_t *state)
{
    if (res == NULL) return NULL;
    int is_neg = res[0] == '-';

    res = apply_precision(res, state, is_neg);
    int sign_space = state->flags.show_sign ||
        state->flags.space_if_pos || is_neg;
    int new_size = (my_strlen(res) > (size_t)state->width ?
        my_strlen(res) : (size_t)state->width) +
        (!state->flags.align_left && sign_space);
    char *new_res = my_calloc(new_size + sign_space + 1, sizeof(char));
    int utils[3] = { sign_space, new_size, is_neg };
    apply_alignment(res, new_res, utils, state);
    free(res);
    return new_res;
}

char *post_processor_uint(char *res, parse_state_t *state)
{
    res = apply_precision(res, state, 0);

    size_t new_size = (my_strlen(res) > (size_t)state->width ?
        my_strlen(res) : (size_t)state->width);

    char *new_res = my_calloc(new_size + 1 + (state->flags.hashtag ? 2 : 0), 1);
    apply_alignment_u(res, new_res, new_size, state);
    free(res);
    return new_res;
}
