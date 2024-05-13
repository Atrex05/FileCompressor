/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map implementation
*/

#ifndef INCLUDE_MY_MAP_
    #define INCLUDE_MY_MAP_
    #include "my_vec.h"
    #include "my_str.h"


typedef struct map_elem_s {
    str_t *key;
    void *data;
} map_elem_t;

typedef struct map_s {
    int capacity;
    vec_void_t *elems;
} map_t;

/**
 * @brief get the keys of a map
 *
 * @param map   the map to get the keys from
 * @return a vector of the keys stored in strings
 */
vec_str_t *map_get_keys(map_t *map);

/**
 * @brief set a value in a map, it will overwrite if it already exists
 *
 * @param map   the map to add the new entry
 * @param key   the key of the entry
 * @param data  the data of the entry
 */
void map_set(map_t *map, str_t *key, void *data);

/**
 * @brief get the value from a map with a given key
 *
 * @param map   the map to get the key from
 * @param key   the key as a string
 * @return the element assiciated with the key, or NULL if undefined
 */
void *map_get(map_t *map, str_t *key);

/**
 * @brief create a new map
 *
 * @param capacity  for better efficiency this value must be as large as the
 *                  number of elements in the map
 * @return a new map
 */
map_t *map_create(int capacity);

/**
 * @brief frees a map along with all its elements
 *        the element with be freeable with only free
 * @param map   the map to free
 */
void map_free(map_t *map);

/**
 * @brief helper function used by map_free to free a map element
 *        normally you shouldn't have use it
 *
 * @param elem  the element to free
 */
void map_elem_free(void *elem);

/**
 * @brief hash a key to find its index in the map
 *        normally you shouldn't have use it
 *
 * @param key   the string of key to hash
 * @return the index of where the data is in the map
 */
unsigned int map_hash_key(str_t *key);


#endif /* INCLUDE_MY_MAP_ */
