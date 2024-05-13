/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lzw encoding
*/

#include "my_str.h"
#include "my_math.h"
#include "my_map.h"
#include "antman/antman.h"

static const unsigned int END_OF_FILE = 256;
static const int CODE_MAX_SIZE = 32767;

static int *malloc_int(int value)
{
    int *data = malloc(sizeof(int));

    if (data == NULL)
        return NULL;

    *data = value;
    return data;
}

static map_t *init_dict(void)
{
    map_t *dict = map_create(CODE_MAX_SIZE);
    int *temp_int = NULL;
    str_t *key = NULL;

    for (int i = 0; i < 256; ++i) {
        temp_int = malloc_int(i);
        key = str_ncreate((char[1]){i}, 1);
        if (temp_int == NULL || key == NULL)
            return NULL;
        map_set(dict, key, temp_int);
        free(key);
    }
    return dict;
}

static void add_new_code_entry(map_t *dict, int *code, str_t **scope[2], char c)
{
    str_t **curr = scope[0];
    str_t **buffer = scope[1];

    if (map_get(dict, *curr) == NULL) {
        if (*code <= CODE_MAX_SIZE)
            map_set(dict, *curr, malloc_int((*code)++));
        str_slice(curr, 0, (*curr)->length - 1);
        write_n_bits(buffer, *(int*)map_get(dict, *curr));
        str_cadd(str_clear(curr), c);
    }
}

str_t *lzw_encode(str_t *file_content)
{
    SMART_MAP map_t *dict = init_dict();
    str_t *buffer = str_create("");
    SMART_STR str_t *curr = str_create("");
    int code = 257;
    char c = 0;

    if (dict == NULL || buffer == NULL || curr == NULL)
        return NULL;
    for (size_t i = 0; i < file_content->length; ++i) {
        c = file_content->data[i];
        str_cadd(&curr, c);
        add_new_code_entry(dict, &code, (str_t **[2]){&curr, &buffer}, c);
    }
    if (curr->length > 0)
        write_n_bits(&buffer, *(int*)map_get(dict, curr));
    write_n_bits(&buffer, END_OF_FILE);
    return buffer;
}
