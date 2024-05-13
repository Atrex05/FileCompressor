/*
** EPITECH PROJECT, 2022
** my_puts.c
** File description:
** displays the characters of a string
*/

#include "my_stdio.h"

void my_puts(char const *str)
{
    my_putstr(str);
    my_putchar('\n');
}
