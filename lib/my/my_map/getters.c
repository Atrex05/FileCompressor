/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** getters
*/

#include "my_vec.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "my_map.h"

void *map_get(map_t *map, str_t *key)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    vec_void_t *cands = NULL;

    if (map->elems->data[hash_idx] == NULL)
        return NULL;

    cands = map->elems->data[hash_idx];

    for (size_t i = 0; i < cands->base.size; i++)
        if (str_eq(((map_elem_t*)cands->data[i])->key, key))
            return ((map_elem_t*)cands->data[i])->data;

    return NULL;
}

vec_str_t *map_get_keys(map_t *map)
{
    vec_str_t *keys = (vec_str_t*)vec_create(map->capacity, sizeof(str_t*));
    vec_void_t *elem_col = NULL;
    str_t *temp = NULL;

    for (size_t i = 0; i < map->elems->base.capacity; i++) {
        elem_col = map->elems->data[i];
        if (elem_col == NULL)
            continue;
        for (size_t j = 0; j < elem_col->base.size; j++) {
            temp = str_dup(((map_elem_t*)elem_col->data[j])->key);
            vec_push_back((vec_t**)&keys, &temp);
        }
    }

    return keys;
}
