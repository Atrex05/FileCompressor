/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for specifier
*/

#ifndef EXEC_SPECIFIER_
    #define EXEC_SPECIFIER_
    #include <stdint.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include "mapper.h"
    #include "state.h"


typedef struct ptr_data_s {
    void *ptr;
    struct buffer_s *first_node;
    char *length_mod;
} ptr_data_t;

typedef struct state_ptr_s {
    void *ptr;
    parse_state_t *state;
} state_ptr_t;

char *exec_speficier(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_float_g(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_ptr(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_char(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_str(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_int(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_uint(va_list *ap, parse_state_t *state, fn_map_t spec);

char *exec_spec_float(va_list *ap, parse_state_t *state, fn_map_t spec);


#endif /* EXEC_SPECIFIER_ */
