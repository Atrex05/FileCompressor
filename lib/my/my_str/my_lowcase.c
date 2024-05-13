/*
** EPITECH PROJECT, 2022
** my_lowcase.c
** File description:
** puts a letter in lowercase
*/

#include "my_str.h"

char my_lowcase(char chr)
{
    if (my_isupper(chr)) {
        return (chr - ('A' - 'a'));
    } else {
        return chr;
    }
}
