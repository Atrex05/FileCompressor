/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked list
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_list.h"

node_t *node_create(void)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = NULL;

    return new_node;
}

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;

    list->front = NULL;
    list->back = NULL;
    list->size = 0;

    return list;
}

void node_free(node_t *node)
{
    free(node->value);
    free(node);
}

void list_free(list_t *list)
{
    node_t *temp = list->front;
    node_t *old = list->front;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        node_free(old);
    }

    free(list);
}
