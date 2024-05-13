/*
** EPITECH PROJECT, 2022
** my_isalphanum.c
** File description:
** returns 1 if char is alphanum
*/

int my_isalphanum(char chr)
{
    return (
        (chr >= 'A' && chr <= 'Z') ||
        (chr >= 'a' && chr <= 'z') ||
        (chr >= '0' && chr <= '9')
    );
}
