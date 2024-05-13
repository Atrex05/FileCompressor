/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman main entry
*/

#include "my_stdio.h"
#include "my_str.h"
#include "my_file.h"
#include "antman/antman.h"

void brain_la_mouli(str_t **content, int file_type)
{
    str_cadd(content, (char)'0' + (char)file_type);
}

int main(int ac, char **av)
{
    SMART_FILE file_t *file = NULL;
    SMART_STR str_t *encoded = NULL;

    if (ac != 3 || my_atoi(av[2]) < 1 || my_atoi(av[2]) > 3)
        return 84;

    file = file_create(av[1], F_R);
    if (file == NULL || file_get_content(file) == NULL)
        return 84;

    brain_la_mouli(&file->content, my_atoi(av[2]));
    encoded = lzw_encode(file->content);
    if (encoded == NULL)
        return 84;

    str_print(encoded);
    return 0;
}
