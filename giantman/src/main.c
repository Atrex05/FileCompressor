/*
** EPITECH PROJECT, 2022
** antman
** File description:
** giantman main entry
*/

#include "my_stdio.h"
#include "my_str.h"
#include "my_file.h"
#include "antman/antman.h"

void brain_la_mouli(str_t **decoded)
{
    str_slice(decoded, 0, (*decoded)->length - 1);
}

int main(int ac, char **av)
{
    SMART_FILE file_t *file = NULL;
    SMART_STR str_t *decoded = NULL;

    if (ac != 3 || my_atoi(av[2]) < 1 || my_atoi(av[2]) > 3)
        return 84;

    file = file_create(av[1], F_R);
    if (file == NULL || file_get_content(file) == NULL)
        return 84;

    decoded = lzw_decode(file->content);
    if (decoded == NULL)
        return 84;

    brain_la_mouli(&decoded);
    str_print(decoded);
    return 0;
}
