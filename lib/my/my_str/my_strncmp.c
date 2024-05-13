/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compares the first n bytes of the two given strings
*/

#include "my_stdlib.h"

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    while (*s1 && *s2 && i < n && *s1 == *s2) {
        s1++;
        s2++;
        i++;
    }

    return *s1 - *s2;
}
