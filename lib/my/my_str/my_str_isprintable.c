/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** returns 1 if every chars of the string is printable
*/

#include "my_str.h"

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isprintable(str[i]))
            return 0;
    }

    return 1;
}
