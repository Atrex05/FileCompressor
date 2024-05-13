/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %g and %G
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "specifiers.h"
#include "state.h"
#include "post_processor.h"
#include "exec_specifier.h"
#include "spec_int_utils.h"
#include "float_utils.h"

static void modify_state_float(
    parse_state_t *state, char *float_str, int precision
)
{
    int len = 0;
    do len++; while (float_str[len] != '.');
    int idx = my_strlen(float_str) - 1;
    int nb_len = 0;
    do nb_len++; while (float_str[idx--] == '0');
    nb_len = my_strlen(float_str) - nb_len;

    if (state->flags.hashtag) {
        state->precision = precision - len;
    } else {
        state->specifier = 'Z';
        if (precision > nb_len) {
            state->precision = len;
        } else {
            state->precision = precision - len;
        }
        if (state->precision <= 0) {
            state->precision = -2;
        }
    }
}

static void modify_state_exp(
    parse_state_t *state, int precision, int exp
)
{
    int null_precision = state->precision == -2;

    if (state->flags.hashtag) {
            state->precision -= 1;
    } else {
        if (precision >= 0) {
            state->precision = precision - 1;
        }
        if ((precision + 1) >= exp) {
            state->precision = precision - exp - 1;
        }
        if (state->precision <= 0) {
            state->precision = 5;
        }
        if (null_precision) {
            state->precision = -2;
        }
        state->specifier = 'Z';
    }
}

static char *generic(
    void *ptr,
    parse_state_t *state,
    char *(*fn_f)(void *ptr),
    char *(*fn_e)(void *ptr)
)
{
    int null_precision = state->precision == -2;
    int precision = (null_precision) ? 1 :
        (state->precision == 0) ? 6 : state->precision;
    int temp = state->width;

    state->width = 0;
    char *exp_str = post_processor_float((*fn_e)(ptr), state);
    state->precision += (null_precision) ? 3 : 1;
    char *float_str = post_processor_float((*fn_f)(ptr), state);
    state->precision -= (null_precision) ? 3 : 1;
    state->width = temp;
    int exp = my_atoi(extract_exp(exp_str) + 1);

    if (exp < -4 || exp >= precision) {
        modify_state_exp(state, precision, exp);
        return post_processor_float((*fn_e)(ptr), state);
    } else {
        modify_state_float(state, float_str, precision);
        return post_processor_float((*fn_f)(ptr), state);
    }
}

char *compute_spec_lo_g(void *ptr)
{
    state_ptr_t *data = (state_ptr_t *)ptr;
    void *pt = data->ptr;
    parse_state_t *state = data->state;

    char *err = handle_errors_float(*(double *)pt, 0);
    if (err != NULL) return err;

    return generic(pt, state, &compute_spec_lo_f, &compute_spec_lo_e);
}

char *compute_spec_up_g(void *ptr)
{
    state_ptr_t *data = (state_ptr_t *)ptr;
    void *pt = data->ptr;
    parse_state_t *state = data->state;

    char *err = handle_errors_float(*(double *)pt, 0);
    if (err != NULL) return err;

    return generic(pt, state, &compute_spec_up_f, &compute_spec_up_e);
}
