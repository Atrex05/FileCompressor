/*
** EPITECH PROJECT, 2022
** my_nbr_length.c
** File description:
** returns the length of a number
*/

int my_nbr_length(long int nb)
{
    int nb_digit = 0;

    if (nb == 0)
        return 1;

    while (nb) {
        nb_digit++;
        nb /= 10;
    }

    return nb_digit;
}
