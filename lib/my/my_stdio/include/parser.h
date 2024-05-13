/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for the parser
*/

#ifndef PARSER_
    #define PARSER_


void parse_flag(const char *format, int *i, parse_state_t *state);

void parse_width(const char *format, int *i, parse_state_t *state);

void parse_is_precision(const char *format, int *i, parse_state_t *state);

void parse_precision(const char *format, int *i, parse_state_t *state);

void parse_length(const char *format, int *i, parse_state_t *state);


#endif /* PARSER_ */
