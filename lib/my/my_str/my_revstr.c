/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverses a string
*/

#include "my_str.h"

char *my_revstr(char *str)
{
    size_t length = my_strlen(str);
    size_t idx = 0;
    char temp;

    while (idx < length / 2) {
        temp = str[idx];
        str[idx] = str[length - idx - 1];
        str[length - idx - 1] = temp;
        idx++;
    }

    return str;
}
