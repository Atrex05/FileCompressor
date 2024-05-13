/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** returns the power of number
*/

int my_pow(int number, int power)
{
    int num = 1;

    for (int i = 0; i < power; i++) {
        num = num * number;
    }

    return num;
}
