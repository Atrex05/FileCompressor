/*
** EPITECH PROJECT, 2022
** my_ll_pow.c
** File description:
** long long pow
*/


long long my_ll_pow(long long number, int power)
{
    long long num = 1;

    for (int i = 0; i < power; i++) {
        num = num * number;
    }

    return num;
}
