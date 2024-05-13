/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copies n characters from a string into another
*/

#include "my_stdlib.h"

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];

    for (; i <= n; i++)
        dest[i] = '\0';

    return dest;
}
