/*
** EPITECH PROJECT, 2022
** my_sprintf
** File description:
** sprintf clone
*/

#include <stddef.h>
#include <stdarg.h>

#include "my_stdlib.h"
#include "core.h"
#include "buffer.h"

int my_vasprintf(char **ret, const char *format, va_list *ap)
{
    buffer_t *buffer = create_buffer();
    int buff_size = 0;

    compute_char(ap, buffer, format);

    buff_size = get_buffer_length(buffer);
    char *tmp = my_calloc(buff_size + 1, sizeof(char));
    add_buffer_to_str(buffer, tmp);
    free_buffer(buffer);

    *ret = tmp;

    return buff_size;
}
