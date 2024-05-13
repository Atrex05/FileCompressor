/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** returns 1 if the given number is prime else 0
*/

static int find_closest_sqrt(int nb)
{
    int sqrt_try = 0;
    int index = 0;

    if (nb % 2 != 0)
        index = 1;

    while (sqrt_try < nb) {
        sqrt_try = index * index;
        index += 2;

        if (index > 46341 + 2)
            return index;
    }

    return index;
}

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1 || nb < 0)
        return 0;

    if (nb == 2 || nb == 3)
        return 1;

    for (int i = 2; i < find_closest_sqrt(nb); i++) {
        if (nb % i == 0)
            return 0;
    }

    return 1;
}
