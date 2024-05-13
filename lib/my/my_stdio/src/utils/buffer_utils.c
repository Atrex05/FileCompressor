/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for buffer
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_stdio.h"
#include "buffer.h"

int get_buffer_length(buffer_t *node)
{
    int size = 0;

    while (node != NULL) {
        size += my_strlen(node->content);
        node = node->next;
    }

    return size;
}

void print_buffer(buffer_t *buffer, int fd)
{
    int size = get_buffer_length(buffer);
    char *to_write = my_calloc(size + 1, sizeof(char));

    while (buffer != NULL) {
        my_strcat(to_write, buffer->content);
        buffer = buffer->next;
    }

    write(fd, to_write, size);

    free(to_write);
}

void add_buffer_to_str(buffer_t *buffer, char *dest)
{
    while (buffer != NULL) {
        my_strcat(dest, buffer->content);
        buffer = buffer->next;
    }
}

void free_buffer(buffer_t *buffer)
{
    buffer_t *old;

    while (buffer != NULL) {
        old = buffer;
        buffer = buffer->next;
        free(old->content);
        free(old);
    }
}
