/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** returns the number of characters of a string
*/

#include "my_stdlib.h"

size_t my_strlen(char const *str)
{
    size_t len = 0;

    while (*str++)
        len++;

    return len;
}
