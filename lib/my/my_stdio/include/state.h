/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for the state management
*/

#ifndef STATE_
    #define STATE_
    #include "buffer.h"


typedef struct parse_state_s {
    struct {
        int align_left;
        int show_sign;
        int space_if_pos;
        int pad_zeros;
        int hashtag;
    } flags;
    int width;
    int precision;
    char length[2];
    char specifier;
    enum {
        FLAG,
        WIDTH,
        IS_PRECISION,
        PRECISION,
        LENGTH_MOD,
        SPECIFIER
    } state_i;
    int is_parsing;
    struct buffer_s *first_node;
} parse_state_t;

void clear_state(parse_state_t *state);


#endif /* STATE_ */
