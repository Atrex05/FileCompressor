/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for the post processor
*/

#ifndef POST_PROCESSOR_
    #define POST_PROCESSOR_
    #include "state.h"


char *post_processor_float(char *float_str, parse_state_t *state);

char *post_processor_int(char *res, parse_state_t *state);

char *post_processor_uint(char *res, parse_state_t *state);

char *post_processor_str(char *res, parse_state_t *state);

void apply_alignment(
    char *res, char *new_res,
    int *utils, parse_state_t *state
);

void apply_alignment_u(
    char *res, char *new_res,
    int new_size, parse_state_t *state
);

char *apply_precision(char *res, parse_state_t *state, int is_neg);

char *extract_exp(char *float_str);

void extract_a_p_hex(char *new_res, char *res, char spec, int is_neg);

char *extract_exp(char *float_str);


#endif /* POST_PROCESSOR_ */
