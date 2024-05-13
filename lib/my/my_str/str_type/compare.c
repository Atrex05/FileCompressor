/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compare
*/

#include "my_str.h"

int str_eq(str_t *s1, str_t *s2)
{
    if (s1->length != s2->length)
        return 0;

    return (str_compare(s1, s2) == 0);
}

int str_ncompare(str_t *s1, str_t *s2, size_t n)
{
    size_t i = 0;
    int status = 0;

    if (s1->length == 0 || s2->length == 0)
        return 1;
    while (
        i < s1->length - 1 && i < s2->length - 1 &&
        i < n && s1->data[i] == s2->data[i]
    ) {
        i++;
    }
    status = s1->data[i] - s2->data[i];

    return status;
}

int str_compare(str_t *s1, str_t *s2)
{
    size_t i = 0;
    int status = 0;

    if (s1->length == 0 || s2->length == 0)
        return 1;
    while (
        i < s1->length - 1 && i < s2->length - 1 &&
        s1->data[i] == s2->data[i]
    ) {
        i++;
    }
    status = s1->data[i] - s2->data[i];

    return status;
}
