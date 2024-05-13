/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lzw decoding
*/

#include "my_str.h"
#include "my_math.h"
#include "my_stdio.h"
#include "antman/antman.h"

static const unsigned int END_OF_FILE = 256;
static const int CODE_MAX_SIZE = 32767;

static vec_str_t *init_dict(void)
{
    vec_str_t *dict =
        (vec_str_t*)vec_create(CODE_MAX_SIZE, sizeof(str_t *));

    my_memset(dict->data, 0, dict->base.capacity * dict->base.el_size);
    for (int i = 0; i <= 255; ++i) {
        dict->data[i] = str_create("");
        str_cadd(dict->data + i, i);
    }
    return dict;
}

static void dict_free(void *ptr)
{
    vec_str_t *dict = *(vec_str_t **)ptr;

    if (dict == NULL)
        return;

    for (size_t i = 0; i <= (size_t)CODE_MAX_SIZE; ++i)
        if (dict->data[i] != NULL)
            free(dict->data[i]);

    free(dict);
}

static void add_new_code_entry(
    vec_str_t *dict, int code, int *new_code, str_t *prev
)
{
    if (prev->length > 0 && *new_code <= CODE_MAX_SIZE) {
        if (dict->data[*new_code] == NULL)
            dict->data[*new_code] = str_create("");
        str_clear(dict->data + *new_code);
        str_stradd(dict->data + *new_code, prev);
        str_cadd(dict->data + *new_code, dict->data[code]->data[0]);
        (*new_code)++;
    }
}

static void add_new_entry(vec_str_t *dict, int code, str_t *prev)
{
    if (dict->data[code] == NULL) {
        dict->data[code] = str_create("");
        str_stradd(dict->data + code, prev);
        str_cadd(dict->data + code, prev->data[0]);
    }
}

str_t *lzw_decode(str_t *file_compressed)
{
    SMART_ANY(dict_free) vec_str_t *dict = init_dict();
    SMART_STR str_t *prev = str_create("");
    str_t *buffer = str_create("");
    int code = 0;
    int new_code = 257;

    while ((code = read_n_bits(file_compressed)) != (int)END_OF_FILE) {
        if (code > CODE_MAX_SIZE) return buffer;
        add_new_entry(dict, code, prev);
        str_stradd(&buffer, dict->data[code]);
        add_new_code_entry(dict, code, &new_code, prev);
        str_stradd(str_clear(&prev), dict->data[code]);
    }
    return buffer;
}
