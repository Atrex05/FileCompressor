/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** list utils
*/

#include "my_stdlib.h"
#include "my_list.h"

void list_push_front(list_t *list, void *value)
{
    node_t *new_node = node_create();
    new_node->value = value;
    list->size++;

    if (list->front == NULL && list->back == NULL) {
        list->front = new_node;
        list->back = new_node;
    } else {
        new_node->next = list->front;
        list->front->prev = new_node;
        list->front = new_node;
    }
}

void list_push_back(list_t *list, void *value)
{
    node_t *new_node = node_create();
    new_node->value = value;
    list->size++;

    if (list->front == NULL && list->back == NULL) {
        list->front = new_node;
        list->back = new_node;
    } else {
        list->back->next = new_node;
        new_node->prev = list->back;
        list->back = new_node;
    }
}

void list_pop_front(list_t *list)
{
    if (list->front == NULL && list->back == NULL) {
        return;
    }

    node_t *temp = list->front;
    list->size--;

    list->front = list->front->next;
    if (list->front == NULL) {
        list->back = NULL;
    } else {
        list->front->prev = NULL;
    }

    node_free(temp);
}

void list_pop_back(list_t *list)
{
    if (list->front == NULL && list->back == NULL) {
        return;
    }

    node_t *temp = list->back;
    list->size--;

    list->back = list->back->prev;

    if (list->back == NULL) {
        list->front = NULL;
    } else {
        list->back->next = NULL;
    }

    node_free(temp);
}
