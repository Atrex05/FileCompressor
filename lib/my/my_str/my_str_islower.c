/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** returns 1 if every chars of the string is lower
*/

#include "my_str.h"

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_islower(str[i]))
            return 0;
    }

    return 1;
}
