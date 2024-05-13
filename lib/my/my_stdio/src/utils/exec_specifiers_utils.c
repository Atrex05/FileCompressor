/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** rest of the exec_specifiers functions
*/

#include <stdarg.h>
#include <wchar.h>

#include "mapper.h"
#include "state.h"
#include "post_processor.h"
#include "exec_specifier.h"

char *exec_spec_ptr(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    void *ptr = va_arg(*ap, void *);
    ptr_data_t ptr_data = {
        .ptr = ptr,
        .length_mod = state->length,
        .first_node = state->first_node
    };
    state->is_parsing = 0;

    return (*spec.func)(&ptr_data);
}

char *exec_spec_float_g(
    va_list *ap, parse_state_t *state, fn_map_t spec
)
{
    double d = 0;
    state_ptr_t ptr_data = { NULL, state };

    switch (state->length[0]) {
        case 'L':
            d = va_arg(*ap, long double);
            ptr_data.ptr = &d;
            return (*spec.func)(&ptr_data);
        default:
            d = va_arg(*ap, double);
            ptr_data.ptr = &d;
            return (*spec.func)(&ptr_data);
    }
}

char *exec_spec_char(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    wint_t arg_wint;
    int arg_int;

    switch (state->length[0]) {
        case 'l':
            arg_wint = va_arg(*ap, wint_t);
            return (*spec.func)(&arg_wint);
        default:
            arg_int = va_arg(*ap, int);
            return (*spec.func)(&arg_int);
    }
}

char *exec_spec_str(va_list *ap, parse_state_t *state, fn_map_t spec)
{
    wchar_t *arg_wchar;
    char *arg_char;

    switch (state->length[0]) {
        case 'l':
            arg_wchar = va_arg(*ap, wchar_t *);
            return (*spec.func)(arg_wchar);
        default:
            arg_char = va_arg(*ap, char *);
            return (*spec.func)(arg_char);
    }
}
