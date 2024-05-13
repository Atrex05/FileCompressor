/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_stdlib declarations
*/

#ifndef INCLUDE_MY_STDLIB_
    #define INCLUDE_MY_STDLIB_
    #include <stdlib.h>

    #define SMART_ANY(fn)   __attribute__((cleanup(fn)))
    #define SMART_STR       SMART_ANY(auto_str_free)
    #define SMART_FILE      SMART_ANY(auto_file_free)
    #define SMART_MAP       SMART_ANY(auto_map_free)
    #define SAMRT_LIST      SMART_ANY(auto_list_free)
    #define SMART_VEC       SMART_ANY(auto_vec_free)

void auto_str_free(void *ptr);
void auto_map_free(void *ptr);
void auto_file_free(void *ptr);
void auto_list_free(void *ptr);
void auto_vec_free(void *ptr);

void *my_calloc(size_t count, size_t elem_size);
char *my_itoa(long int nb);
int my_atoi(char const *str);
double my_atof(char const *str);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *dest, char c, size_t len);
void vfree(int argc, ...);


#endif /* INCLUDE_MY_STDLIB_ */
