/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** puts every letter in lowercase
*/

#include "my_str.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = my_lowcase(str[i]);

    return str;
}
