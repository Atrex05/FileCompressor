/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** returns 1 if every chars of the string is alpha
*/

#include "my_str.h"

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isalpha(str[i]))
            return 0;
    }

    return 1;
}
