/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked_list declarations
*/

#ifndef INCLUDE_MY_LIST_
    #define INCLUDE_MY_LIST_


typedef struct node_s {
    void *value;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *front;
    node_t *back;
    int size;
} list_t;

/**
 * @brief creates a doubly linked list
 *
 * @return a new list
 */
list_t *list_create(void);

/**
 * @brief frees a list and its content
 *        the content has to be freeable with a single free
 *
 * @param list the list to free
 */
void list_free(list_t *list);

/**
 * @brief adds a new element to the front of a list
 *
 * @param list  the list to add the element to
 * @param value the value of the element
 */
void list_push_front(list_t *list, void *value);

/**
 * @brief adds a new element to the back of a list
 *
 * @param list  the list to add the element to
 * @param value the value of the element
 */
void list_push_back(list_t *list, void *value);

/**
 * @brief removes the first element of a list
 *
 * @param list  the list to remove the element from
 */
void list_pop_front(list_t *list);

/**
 * @brief removes the last element of a list
 *
 * @param list  the list to remove the element from
 */
void list_pop_back(list_t *list);

/**
 * @brief runs a functions on every element of a list
 *
 * @param list  the list to preform the logic on
 * @param fn    the function to call, it will be called like this:
 *              fn(current_elem_in_list->data, data);
 * @param data  additionnal data that you can use in the fn
 */
void list_for_each(list_t *list, void (*fn)(void *, void *), void *data);

/**
 * @brief frees a node of a list
 *
 * @param node  the node to free
 */
void node_free(node_t *node);

/**
 * @brief creates a node for a list
 *
 * @return a new node
 */
node_t *node_create(void);


#endif /* INCLUDE_MY_LIST_ */
