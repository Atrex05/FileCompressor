/*
** EPITECH PROJECT, 2022
** my_isprintable.c
** File description:
** returns 1 if char is printable
*/

int my_isprintable(char chr)
{
    return (
        chr >= ' ' && chr <= '~'
    );
}
