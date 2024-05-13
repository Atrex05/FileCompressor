/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** % parser
*/

#include "my_stdlib.h"
#include "my_math.h"
#include "my_str.h"
#include "state.h"

void parse_flag(const char *format, int *i, parse_state_t *state)
{
    switch (format[*i]) {
        case '+': state->flags.show_sign = 1; break;
        case '-': state->flags.align_left = 1; break;
        case ' ': state->flags.space_if_pos = 1; break;
        case '0': state->flags.pad_zeros = 1; break;
        case '#': state->flags.hashtag = 1; break;
        default:
            (*i)--;
            state->state_i = WIDTH;
    }

    (*i)++;
}

void parse_width(const char *format, int *i, parse_state_t *state)
{
    state->state_i = IS_PRECISION;

    if (format[*i] == '*') {
        state->width = -1;
        (*i)++;
        return;
    }

    state->width = my_atoi(&(format[*i]));
    if (state->width > 0) {
        (*i) += my_nbr_length(state->width);
    }
}

void parse_is_precision(const char *format, int *i, parse_state_t *state)
{
    if (format[*i] == '.') {
        state->state_i = PRECISION;
        (*i)++;
    } else {
        state->state_i = LENGTH_MOD;
    }
}

void parse_precision(const char *format, int *i, parse_state_t *state)
{
    state->state_i = LENGTH_MOD;

    if (format[*i] == '*') {
        state->precision = -1;
        (*i)++;
        return;
    }

    if (my_isnum(format[*i])) {
        state->precision = my_atoi(&(format[*i]));
        if (state->precision == 0)
            state->precision = -2;
        (*i) += my_nbr_length(state->precision);
    } else {
        state->precision = -2;
    }
}

void parse_length(const char *format, int *i, parse_state_t *state)
{
    if (state->length[0] == '\0') {
        if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j' ||
            format[*i] == 'z' || format[*i] == 't' || format[*i] == 'L'
        ) {
            state->length[0] = format[*i];
            (*i)++;
        } else {
            state->state_i = SPECIFIER;
        }
    } else {
        if (format[*i] == 'h' || format[*i] == 'l') {
            state->length[1] = format[*i];
            (*i)++;
        }
        state->state_i = SPECIFIER;
    }
}
