/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#ifndef INCLUDE_MY_VEC_
    #define INCLUDE_MY_VEC_
    #include "my_stdlib.h"
    #define MAX_VEC_ELEM_SIZE   (1024)


typedef struct vec_base_s {
    size_t capacity;
    size_t size;
    size_t el_size;
} vec_base_t;

typedef struct vec_s {
    vec_base_t base;
    char data[0];
} vec_t;

typedef struct vec_int_s {
    vec_base_t base;
    int data[0];
} vec_int_t;

typedef struct vec_void_s {
    vec_base_t base;
    void *data[0];
} vec_void_t;

size_t get_padded_size(size_t size);

/**
 * @brief runs a functions on every element of a vector
 *
 * @param vec   the vector to preform the logic on
 * @param fn    the function to call, it will be called like this:
 *              fn(current_elem_in_vec, data);
 * @param data  additionnal data that you can use in the fn
 */
void vec_for_each(vec_t *vec, void (*fn)(void *, void *), void *data);

/**
 * @brief clears a vector
 *
 * @param vec   the vector to clear
 */
void vec_clear(vec_t *vec);

/**
 * @brief removes an element from a vector at a given index
 *
 * @param vec   the vector to remove the element from
 * @param idx   the index of the element to remove
 */
void vec_remove(vec_t *vec, size_t idx);

/**
 * @brief inserts an element into a vector at a given index
 *
 * @param vec   the vector to insert the element in
 * @param elem  the element to insert
 * @param idx   the index at which the element will be inserted
 */
void vec_insert(vec_t **vec, void *elem, size_t idx);

/**
 * @brief resizes a vector to a new given size
 *
 * @param vec       the vector to resize
 * @param new_size  the new size
 */
void vec_resize(vec_t **vec, size_t new_size);

/**
 * @brief adds an element at the back of a vector
 *
 * @param vec   the vector to append the element to
 * @param elem  the element to add
 */
void vec_push_back(vec_t **vec, void *elem);

/**
 * @brief sorts a vector
 *
 * @param vec       the vector to sort
 * @param cmp_fn    function to compare 2 elements
 */
void vec_sort(vec_t *vec, int (*cmp_fn)(vec_t *, size_t, size_t));

/**
 * @brief swaps 2 elements in a vector
 *
 * @param vec   the vector to perform the swap on
 * @param i     the index of the 1st element
 * @param j     the index of the 2nd element
 */
void vec_swap(vec_t *vec, size_t i, size_t j);

/**
 * @brief frees a vector composed of pointers
 *
 * @param vec       the vector to free
 * @param free_fn   the function to free an element
 */
void vec_free(vec_t *vec, void (*free_fn)(void *));

/**
 * @brief creates a vector
 *
 * @param nb_data   the number of elements in the vector
 * @param el_size   the size of an element of the vector
 * @return the created vector
 */
vec_t *vec_create(size_t nb_data, size_t el_size);


#endif /* INCLUDE_MY_VEC_ */
