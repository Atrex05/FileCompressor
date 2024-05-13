/*
** EPITECH PROJECT, 2022
** my_isalpha.c
** File description:
** return 1 if char is alpha
*/

int my_isalpha(char chr)
{
    return (
        (chr >= 'A' && chr <= 'Z') ||
        (chr >= 'a' && chr <= 'z')
    );
}
