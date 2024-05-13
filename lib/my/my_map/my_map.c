/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map implementation
*/

#include "my_map.h"
#include "my_vec.h"
#include "my_str.h"

map_t *map_create(int capacity)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        return NULL;

    map->capacity = capacity;
    map->elems = (vec_void_t*)vec_create(capacity, sizeof(void*));
    my_memset(map->elems->data, 0, sizeof(void*) * map->elems->base.capacity);

    return map;
}

void map_elem_free(void *elem)
{
    map_elem_t *temp = elem;
    free(temp->data);
    free(temp->key);
    free(temp);
}

void map_free(map_t *map)
{
    vec_void_t *elem_col = NULL;

    for (size_t i = 0; i < map->elems->base.capacity; i++) {
        elem_col = map->elems->data[i];
        if (elem_col == NULL)
            continue;
        vec_free((vec_t*)elem_col, &map_elem_free);
    }
    free(map->elems);
    free(map);
}
