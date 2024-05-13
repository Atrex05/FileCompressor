/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** concats the two given strings until it reaches nb
*/

#include "my_str.h"

char *my_strncat(char *dest, char const *src, size_t n)
{
    size_t dest_len = my_strlen(dest);
    size_t i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}
