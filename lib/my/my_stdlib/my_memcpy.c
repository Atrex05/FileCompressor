/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_chr = dest;
    const char *src_chr = src;

    while (n--)
        *dest_chr++ = *src_chr++;

    return dest;
}
