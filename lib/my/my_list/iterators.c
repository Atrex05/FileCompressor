/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** iterators
*/

#include "my_stdlib.h"
#include "my_list.h"

void list_for_each(list_t *list, void (*fn)(void *, void *), void *data)
{
    node_t *temp = list->front;

    while (temp != NULL) {
        fn(temp->value, data);
        temp = temp->next;
    }
}
