/*
** EPITECH PROJECT, 2022
** my_int_sqrt.c
** File description:
** returns the sqrt of a given number if the sqrt is whole
** else returns 0
*/

int my_int_sqrt(int nb)
{
    int sqrt_try = 0;
    int index = (nb % 2 != 0) ? 1 : 0;

    if (nb <= 0)
        return 0;

    while (sqrt_try < nb) {
        sqrt_try = index * index;
        index += 2;

        if (index > 46341 + 2)
            return 0;
    }

    if (sqrt_try == nb)
        return index - 2;

    return 0;
}
