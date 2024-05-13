/*
** EPITECH PROJECT, 2022
** my_upcase.c
** File description:
** puts a letter in uppercase
*/

#include "my_str.h"

char my_upcase(char chr)
{
    if (my_islower(chr)) {
        return (chr - ('a' - 'A'));
    } else {
        return chr;
    }
}
