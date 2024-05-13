/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf core function mapper
*/

#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "my_str.h"
#include "my_stdlib.h"
#include "buffer.h"
#include "mapper.h"
#include "state.h"
#include "parser.h"
#include "exec_specifier.h"
#include "specifiers.h"

static const fn_map_t SPECIFIERS[] = {
    { 'd', &compute_spec_d },
    { 'i', &compute_spec_d },

    { 'u', &compute_spec_u },
    { 'b', &compute_spec_b },
    { 'o', &compute_spec_o },
    { 'x', &compute_spec_lo_x },
    { 'X', &compute_spec_up_x },

    { 'S', &compute_spec_up_s },
    { 's', &compute_spec_lo_s },
    { 'c', &compute_spec_c },
    { '%', &compute_spec_percent },

    { 'f', &compute_spec_lo_f },
    { 'F', &compute_spec_up_f },
    { 'e', &compute_spec_lo_e },
    { 'E', &compute_spec_up_e },
    { 'g', &compute_spec_lo_g },
    { 'G', &compute_spec_up_g },
    { 'a', &compute_spec_lo_a },
    { 'A', &compute_spec_up_a },

    { 'p', &compute_spec_p },
    { 'n', &compute_spec_n },

    { 'T', &compute_spec_t },
};

static const int SPECIFIER_SIZE = sizeof(SPECIFIERS) / sizeof(fn_map_t);

static void align_from_pwr(parse_state_t *state)
{
    if (state->width < 0) {
        state->width *= -1;
        state->flags.align_left = 1;
    }
}

static char *parse_specifier(
    va_list *ap, const char *format,
    int *i, parse_state_t *state
)
{
    char *res = NULL;

    for (int k = 0; k < SPECIFIER_SIZE; k++) {
        if (SPECIFIERS[k].key != format[*i]) continue;

        if (state->width == -1) {
            state->width = (int)va_arg(*ap, int);
            align_from_pwr(state);
        }
        if (state->precision == -1)
            state->precision = (int)va_arg(*ap, int);

        state->specifier = SPECIFIERS[k].key;
        res = exec_speficier(ap, state, SPECIFIERS[k]);
    }
    if (res == NULL)
        return my_strdup("%");
    (*i)++;
    clear_state(state);
    return res;
}

static char *parse_wrapper(
    va_list *ap, const char *format,
    int *i, parse_state_t *state
)
{
    switch (state->state_i) {
        case FLAG:
            parse_flag(format, i, state); break;
        case WIDTH:
            parse_width(format, i, state); break;
        case IS_PRECISION:
            parse_is_precision(format, i, state); break;
        case PRECISION:
            parse_precision(format, i, state); break;
        case LENGTH_MOD:
            parse_length(format, i, state); break;
        case SPECIFIER:
            return parse_specifier(ap, format, i, state);
    }

    return NULL;
}

static int is_not_percent(
    char *format, int *is_parsing,
    int *i, buffer_t **buffer
)
{
    if (format[*i] != '%' && !*is_parsing) {
        *buffer = add_chr_to_buffer(*buffer, format[*i]);
        (*i)++;
        return 1;
    }
    if (format[*i] == '%' && !*is_parsing) {
        *is_parsing = 1;
        (*i)++;
        return 1;
    }

    return 0;
}

int compute_char(va_list *ap, buffer_t *buffer, char *format)
{
    char *res;
    parse_state_t state = {0};
    state.first_node = buffer;
    int i = 0;

    while (format[i] != '\0') {
        if (is_not_percent(format, &(state.is_parsing), &i, &buffer)) continue;

        res = parse_wrapper(ap, format, &i, &state);

        if (res != NULL) {
            buffer = add_str_to_buffer(buffer, res);
            state.is_parsing = 0;
            free(res);
        }
    }

    return 0;
}
