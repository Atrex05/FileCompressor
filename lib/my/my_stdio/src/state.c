/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** state management for the parser
*/

#include "state.h"

void clear_state(parse_state_t *state)
{
    state->flags.align_left = 0;
    state->flags.hashtag = 0;
    state->flags.pad_zeros = 0;
    state->flags.show_sign = 0;
    state->flags.space_if_pos = 0;

    state->width = 0;
    state->precision = 0;
    state->length[0] = 0;
    state->length[1] = 0;
    state->state_i = 0;
}
