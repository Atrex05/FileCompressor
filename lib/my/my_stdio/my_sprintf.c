/*
** EPITECH PROJECT, 2022
** my_sprintf
** File description:
** sprintf clone
*/

#include <stddef.h>
#include <stdarg.h>

#include "core.h"
#include "buffer.h"

int my_sprintf(char *str, const char *format, ...)
{
    va_list ap;
    buffer_t *buffer = create_buffer();
    int buff_size = 0;

    va_start(ap, format);
    compute_char(&ap, buffer, format);
    va_end(ap);

    add_buffer_to_str(buffer, str);
    buff_size = get_buffer_length(buffer);
    free_buffer(buffer);

    return buff_size;
}
