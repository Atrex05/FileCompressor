/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** not made yet
*/

#include "my_str.h"

char *my_strcat(char *dest, char const *src)
{
    int str_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[str_len + i] = src[i];

    dest[str_len + i] = '\0';

    return dest;
}
