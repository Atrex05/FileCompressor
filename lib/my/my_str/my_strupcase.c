/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** puts every letter in uppercase
*/

#include "my_str.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = my_upcase(str[i]);

    return str;
}
