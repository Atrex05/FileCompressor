/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** va_arg free
*/

#include <stdarg.h>
#include "my_stdlib.h"

void vfree(int argc, ...)
{
    va_list ap;

    va_start(ap, argc);
    while (argc--)
        free(va_arg(ap, void *));
    va_end(ap);
}
