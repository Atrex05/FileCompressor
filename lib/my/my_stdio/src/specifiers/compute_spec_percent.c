/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %%
*/

#include "my_stdlib.h"

char *compute_spec_percent(void *ptr)
{
    (void)ptr;
    char *res = my_calloc(2, sizeof(char));
    res[0] = '%';
    return res;
}
