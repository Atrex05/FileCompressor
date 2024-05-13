/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** clone of printf
*/

#include <stdarg.h>

#include "core.h"
#include "buffer.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    buffer_t *buffer = create_buffer();
    int buff_size = 0;

    va_start(ap, format);
    compute_char(&ap, buffer, format);
    va_end(ap);

    print_buffer(buffer, 1);
    buff_size = get_buffer_length(buffer);
    free_buffer(buffer);

    return buff_size;
}
