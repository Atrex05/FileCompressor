/*
** EPITECH PROJECT, 2022
** my_putstderr.c
** File description:
** printfs a string to the error output
*/

#include "my_stdio.h"
#include "my_str.h"

void my_putstderr(char const *str)
{
    write(2, str, my_strlen(str));
}
