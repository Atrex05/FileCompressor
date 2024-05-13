/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memset(void *dest, char c, size_t len)
{
    char *dest_chr = dest;

    while (len--)
        *dest_chr++ = c;

    return dest;
}
