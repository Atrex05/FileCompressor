/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** buffer helper functions
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_stdio.h"
#include "buffer.h"

buffer_t *create_buffer(void)
{
    buffer_t *node = malloc(sizeof(buffer_t));

    node->content = my_calloc(BUFF_MAX_SIZE + 1, sizeof(char));
    node->next = NULL;

    return node;
}

buffer_t *increase_buffer(buffer_t *last_node)
{
    buffer_t *new_node = create_buffer();
    last_node->next = new_node;

    return new_node;
}

buffer_t *add_chr_to_buffer(buffer_t *buffer, char c)
{
    int i = 0;

    if (my_strlen(buffer->content) == BUFF_MAX_SIZE) {
        buffer = increase_buffer(buffer);
    }

    while (buffer->content[i] != '\0') i++;

    buffer->content[i] = c;

    return buffer;
}

buffer_t *add_str_to_buffer(buffer_t *buffer, char *str)
{
    int buffer_i = my_strlen(buffer->content);

    for (int i = 0; str[i] != '\0'; i++) {
        if (buffer_i == BUFF_MAX_SIZE) {
            buffer = increase_buffer(buffer);
            buffer_i = 0;
        }

        buffer->content[buffer_i] = str[i];
        buffer_i++;
    }

    return buffer;
}
