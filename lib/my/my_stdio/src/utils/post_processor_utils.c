/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for post processor
*/

#include "my_str.h"
#include "my_stdlib.h"

#include "state.h"
#include "post_processor.h"

char *apply_precision(char *res, parse_state_t *state, int is_neg)
{
    int len = my_strlen(res) - is_neg;

    if (state->precision <= 0 || state->precision <= len) {
        return res;
    }

    char *new_res = my_memset(
        my_calloc(state->precision + 1, sizeof(char)), '0', state->precision);
    new_res[state->precision - len] = '\0';

    my_strcat(new_res, res);
    free(res);
    return new_res;
}

static void pad_str(char *new_res, int start, int end, char pad)
{
    for (int i = start; i < end; i++) {
        new_res[i] = pad;
    }
}

static void add_pos_sign(
    char *new_res, int sign_space,
    int is_neg, parse_state_t *state
)
{
    if (sign_space && !is_neg) {
        my_strcat(new_res, state->flags.space_if_pos ? " " : "+");
    }
}

void apply_alignment(
    char *res, char *new_res,
    int *utils, parse_state_t *state
)
{
    int sign_space = utils[0];
    int new_size = utils[1];
    int is_neg = utils[2];
    if (state->flags.align_left) {
        add_pos_sign(new_res, sign_space, is_neg, state);
        extract_a_p_hex(new_res, res, state->specifier, sign_space);
        my_strcat(new_res, res);
        pad_str(new_res, my_strlen(res) +
            (sign_space && !is_neg), new_size, ' ');
    } else {
        if (state->flags.pad_zeros)
            pad_str(new_res, 0, new_size - my_strlen(res) -
                sign_space - ((sign_space) && !is_neg), '0');
        else
            pad_str(new_res, 0, new_size - my_strlen(res) -
                sign_space - ((sign_space) && !is_neg), ' ');
        add_pos_sign(new_res, sign_space, is_neg, state);
        extract_a_p_hex(new_res, res, state->specifier, sign_space);
        my_strcat(new_res, res);
    }
}

void apply_alignment_u(
    char *res, char *new_res,
    int new_size, parse_state_t *state
)
{
    char *hash_tag = state->specifier == 'x' ? "0x" : state->specifier == 'X' ?
        "0X" : state->specifier == 'b' ? "0b" : state->specifier == 'o' ?
        "0" : "";
    int res_null = my_strlen(res) == 0;

    if (state->flags.align_left) {
        if (state->flags.hashtag && !res_null) my_strcat(new_res, hash_tag);
        my_strcat(new_res, res_null ? "0" : res);
        pad_str(new_res, my_strlen(res), new_size, ' ');
    } else {
        if (state->flags.pad_zeros && state->precision == 0)
            pad_str(new_res, 0, new_size - my_strlen(res), '0');
        else
            pad_str(new_res, 0, new_size - my_strlen(res) -
                (state->flags.hashtag ? 2 : 0), ' ');

        if (state->flags.hashtag && !res_null) my_strcat(new_res, hash_tag);
        my_strcat(new_res, res_null ? "0" : res);
    }
}
