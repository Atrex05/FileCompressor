/*
** EPITECH PROJECT, 2022
** antman
** File description:
** checks
*/

#include "my_str.h"

int str_contains(str_t *str, char c)
{
    for (size_t i = 0; i < str->length; ++i)
        if (str->data[i] == c)
            return 1;

    return 0;
}

int str_startswith(str_t *str, str_t *start)
{
    int status = str_ncompare(str, start, start->length) == 0;

    return status;
}

int str_endsswith(str_t *str, str_t *end)
{
    long start = str->length - end->length;
    size_t i = 0;
    int status = 0;

    if (start >= 0) {
        while (i < str->length && str->data[i] == end->data[i])
            i++;
        status = str->data[i] - end->data[i];
    }

    return status;
}
