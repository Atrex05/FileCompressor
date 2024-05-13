/*
** EPITECH PROJECT, 2022
** my_yaml
** File description:
** VERY SIMPLE and LIMITED YAML parser
*/

#include "my_map.h"
#include "my_str.h"
#include "my_file.h"
#include "my_yaml.h"

static const char LINE_DELIM[] = "\n";
static const char DATA_DELIM[] = ":";

static int get_type(char *str)
{
    if (my_str_isint(str))
        return YAML_INT;
    if (my_str_isfloat(str))
        return YAML_DOUBLE;
    return YAML_STR;
}

static void add_type_dispatch(map_t *map, str_t *key, str_t *data)
{
    yaml_elem_t *elem = NULL;
    int type = get_type(data->data);

    switch (type) {
        case YAML_INT:
            elem = malloc(sizeof(yaml_elem_t) + sizeof(int));
            int temp_i = my_atoi(data->data);
            my_memcpy(elem->data, &temp_i, sizeof(int));
            break;
        case YAML_DOUBLE:
            elem = malloc(sizeof(yaml_elem_t) + sizeof(double));
            double temp_d = my_atof(data->data);
            my_memcpy(elem->data, &temp_d, sizeof(double));
            break;
        case YAML_STR:
            elem = malloc(sizeof(yaml_elem_t) + (data->length + 1));
            my_strcpy(elem->data, data->data);
            break;
    } elem->type = type;
    map_set(map, key, elem);
}

yaml_elem_t *yaml_get(map_t *map, str_t *key)
{
    return (yaml_elem_t*)map_get(map, key);
}

map_t *yaml_parse(char const *file_path)
{
    SMART_FILE file_t *file = file_create(file_path, F_R);
    SMART_STR str_t *line_delim = str_create(LINE_DELIM);
    SMART_STR str_t *data_delim = str_create(DATA_DELIM);
    if (!file || !line_delim || !data_delim)
        return NULL;
    file_get_content(file);
    vec_str_t *content = str_split(file->content, line_delim);
    map_t *map = map_create(content->base.size);
    vec_str_t *split_ = NULL;

    for (size_t i = 0; i < content->base.size; i++) {
        split_ = str_split(content->data[i], data_delim);
        if (split_->base.size == 2) {
            str_trim(split_->data, ' ');
            str_trim(split_->data + 1, ' ');
            add_type_dispatch(map, split_->data[0], split_->data[1]);
        } vec_free((vec_t*)split_, &free);
    }
    vec_free((vec_t*)content, &free);
    return map;
}
