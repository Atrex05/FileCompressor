/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** returns 1 if every chars of the string is upper
*/

#include "my_str.h"

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isupper(str[i]))
            return 0;
    }

    return 1;
}
