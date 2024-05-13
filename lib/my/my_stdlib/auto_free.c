/*
** EPITECH PROJECT, 2022
** antman
** File description:
** auto_free
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_list.h"
#include "my_map.h"
#include "my_vec.h"
#include "my_file.h"

void auto_str_free(void *ptr)
{
    str_t *str = *(str_t **)ptr;
    if (str == NULL)
        return;
    free(str);
}

void auto_file_free(void *ptr)
{
    file_t *file = *(file_t **)ptr;
    if (file == NULL)
        return;
    file_free(file);
}

void auto_map_free(void *ptr)
{
    map_t *map = *(map_t **)ptr;
    if (map == NULL)
        return;
    map_free(map);
}

void auto_list_free(void *ptr)
{
    list_t *list = *(list_t **)ptr;
    if (list == NULL)
        return;
    list_free(list);
}

void auto_vec_free(void *ptr)
{
    vec_t *vec = *(vec_t **)ptr;
    if (vec == NULL)
        return;
    free(vec);
}
