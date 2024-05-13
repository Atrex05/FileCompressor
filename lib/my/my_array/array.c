/*
** EPITECH PROJECT, 2022
** my_array
** File description:
** array utils
*/

#include "my_stdlib.h"

int arr_len(void **arr)
{
    int len = 0;

    while (*arr++ != NULL) {
        len++;
    }

    return len;
}

void arr_free(void **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }

    free(arr);
}
