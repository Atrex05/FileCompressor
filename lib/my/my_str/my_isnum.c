/*
** EPITECH PROJECT, 2022
** my_isnum.c
** File description:
** returns 1 if char is numeric
*/

int my_isnum(char chr)
{
    return (
        chr >= '0' && chr <= '9'
    );
}
