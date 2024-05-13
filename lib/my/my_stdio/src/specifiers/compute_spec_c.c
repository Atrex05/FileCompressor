/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %c
*/

#include "my_stdlib.h"

char *compute_spec_c(void *ptr)
{
    char c = *(char *)ptr;
    char *res = my_calloc(2, sizeof(char));
    res[0] = c;
    return res;
}
