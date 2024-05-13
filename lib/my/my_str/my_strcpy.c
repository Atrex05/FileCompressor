/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copies a string into an other
*/

#include "my_stdlib.h"

void my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];

    dest[i] = '\0';
}
