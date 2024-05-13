/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** setters
*/

#include "my_map.h"
#include "my_vec.h"
#include "my_str.h"

static int overwrite_if_in_map(vec_void_t *cands, str_t *key, void *data)
{
    for (size_t i = 0; i < cands->base.size; i++) {
        if (str_eq(((map_elem_t*)cands->data[i])->key, key)) {
            ((map_elem_t*)cands->data[i])->data = data;
            return 1;
        }
    }

    return 0;
}

void map_set(map_t *map, str_t *key, void *data)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    map_elem_t *elem = NULL;

    if (map->elems->data[hash_idx] == NULL) {
        vec_void_t *temp = (vec_void_t*)vec_create(10, sizeof(void*));
        vec_insert((vec_t**)&map->elems, &temp, hash_idx);
    }
    if (overwrite_if_in_map(map->elems->data[hash_idx], key, data))
        return;
    elem = malloc(sizeof(map_elem_t));
    if (elem == NULL)
        return;
    elem->key = str_dup(key);
    elem->data = data;
    vec_push_back((vec_t**)map->elems->data + hash_idx, &elem);
}
