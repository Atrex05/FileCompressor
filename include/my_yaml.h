/*
** EPITECH PROJECT, 2022
** my_yaml
** File description:
** VERY SIMPLE and LIMITED YAML parser
*/

#ifndef INCLUDE_MY_YAML_
    #define INCLUDE_MY_YAML_
    #include "my_map.h"


enum yaml_type_e {
    YAML_INT,
    YAML_DOUBLE,
    YAML_STR
};

typedef struct yaml_elem_s {
    enum yaml_type_e type;
    char data[0];
} yaml_elem_t;

yaml_elem_t *yaml_get(map_t *map, str_t *key);
map_t *yaml_parse(char const *file_path);


#endif /* INCLUDE_MY_YAML_ */
