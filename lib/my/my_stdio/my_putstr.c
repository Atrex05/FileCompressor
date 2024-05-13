/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** displays the characters of a string
*/

#include "my_stdio.h"
#include "my_str.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
