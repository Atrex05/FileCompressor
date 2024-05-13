/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for function mapper
*/

#ifndef MAPPER_
    #define MAPPER_
    #include "state.h"


typedef struct fn_map_s {
    char key;
    char *(*func)(void *ptr);
} fn_map_t;

typedef struct fn_map_exec_s {
    char key;
    char *(*post_proc)(char *res, parse_state_t *state);
    char *(*spec_exec)(va_list *ap, parse_state_t *state, fn_map_t spec);
} fn_map_exec_t;


#endif /* MAPPER_ */
