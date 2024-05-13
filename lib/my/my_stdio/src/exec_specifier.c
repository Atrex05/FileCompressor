/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** exec specifier from length_mod type
*/

#include <stdarg.h>

#include "mapper.h"
#include "exec_specifier.h"
#include "state.h"
#include "post_processor.h"

static const fn_map_exec_t SPEC_EXEC[] = {
    { 'd', &post_processor_int, &exec_spec_int },
    { 'i', &post_processor_int, &exec_spec_int },

    { 'u', &post_processor_uint, &exec_spec_uint },
    { 'b', &post_processor_uint, &exec_spec_uint },
    { 'o', &post_processor_uint, &exec_spec_uint },
    { 'x', &post_processor_uint, &exec_spec_uint },
    { 'X', &post_processor_uint, &exec_spec_uint },

    { 'f', &post_processor_float, &exec_spec_float },
    { 'F', &post_processor_float, &exec_spec_float },
    { 'e', &post_processor_float, &exec_spec_float },
    { 'E', &post_processor_float, &exec_spec_float },
    { 'a', &post_processor_float, &exec_spec_float },
    { 'A', &post_processor_float, &exec_spec_float },

    { 'g', &post_processor_uint, &exec_spec_float_g },
    { 'G', &post_processor_uint, &exec_spec_float_g },

    { 'p', &post_processor_int, &exec_spec_ptr },
    { 'n', &post_processor_int, &exec_spec_ptr },

    { 'S', &post_processor_str, &exec_spec_str },
    { 's', &post_processor_str, &exec_spec_str },

    { 'c', &post_processor_str, &exec_spec_char },

    { 'T', NULL, &exec_spec_ptr },

    { '%', NULL, NULL },
};

static const int SPEC_EXEC_SIZE = sizeof(SPEC_EXEC) / sizeof(fn_map_exec_t);

char *exec_spec_int(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    long long int arg = 0;

    switch (state->length[0]) {
        case 'h': arg = (state->length[1] == 'h') ?
            (signed char)va_arg(*ap, int) : (short)va_arg(*ap, int); break;
        case 'l': arg = (state->length[1] == 'l') ?
            va_arg(*ap, long long int) : va_arg(*ap, long int); break;
        case 'j': arg = va_arg(*ap, intmax_t); break;
        case 'z': arg = va_arg(*ap, size_t); break;
        case 't': arg = va_arg(*ap, ptrdiff_t); break;
        default: arg = va_arg(*ap, int);
    }

    return (*spec.func)(&arg);
}

char *exec_spec_uint(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    unsigned long long int new = 0;

    switch (state->length[0]) {
        case 'h': new = (state->length[1] == 'h') ?
            (unsigned char)va_arg(*ap, int) :
            (unsigned short int)va_arg(*ap, int); break;
        case 'l': new = (state->length[1] == 'l') ?
            va_arg(*ap, unsigned long long int) :
            va_arg(*ap, unsigned long int); break;
        case 'j': new = va_arg(*ap, uintmax_t); break;
        case 'z': new = va_arg(*ap, size_t); break;
        case 't': new = va_arg(*ap, ptrdiff_t); break;
        default: new = va_arg(*ap, unsigned int);
    }

    return (*spec.func)(&new);
}

char *exec_spec_float(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    double d = 0.0;

    switch (state->length[0]) {
        case 'L': d = va_arg(*ap, long double); break;
        default: d = va_arg(*ap, double);
    }

    return (*spec.func)(&d);
}

char *exec_speficier(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    char key = spec.key;
    char *res = NULL;

    for (int i = 0; i < SPEC_EXEC_SIZE; i++) {
        if (SPEC_EXEC[i].key != key) {
            continue;
        }
        if ((*SPEC_EXEC[i].spec_exec) != NULL) {
            res = (*SPEC_EXEC[i].spec_exec)(ap, state, spec);
        } else {
            res = (*spec.func)(NULL);
        }
        if ((*SPEC_EXEC[i].post_proc) != NULL) {
            res = (*SPEC_EXEC[i].post_proc)(res, state);
        }
        break;
    }

    return res;
}
