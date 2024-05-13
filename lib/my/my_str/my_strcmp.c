/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compares the two given strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
