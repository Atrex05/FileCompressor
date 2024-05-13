/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %s and %S
*/

#include <stddef.h>

#include "my_str.h"
#include "my_stdlib.h"
#include "spec_int_utils.h"

static char *get_octal(unsigned char oct)
{
    char const *base = "01234567";

    int base_len = my_strlen(base);
    int new_length = 4;

    int utils[] = { 3, base_len };
    char *str = my_memset(
        my_calloc(new_length + 1, sizeof(char)), '0', new_length);
    str[0] = '\\';

    compute_number(str, base, oct, utils);

    return str;
}

static int my_strlen_octal(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~') {
            len++;
            continue;
        }

        len += my_strlen(get_octal(str[i]));
    }

    return len;
}

char *compute_spec_up_s(void *ptr)
{
    char *str = (char *)ptr;
    char *res = my_calloc('\0', sizeof(char) * (my_strlen_octal(str) + 1));
    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~') {
            res[idx++] = str[i];
            continue;
        }

        char *tmp = get_octal(str[i]);
        my_strcat(res, tmp);
        idx += my_strlen(tmp);
    }

    return res;
}

char *compute_spec_lo_s(void *ptr)
{
    char *str = (char *)ptr;

    if (str != NULL) {
        char *res = my_calloc(my_strlen(str) + 1, sizeof(char));
        my_strcat(res, str);
        return res;
    } else {
        return my_strdup("(null)");
    }
}
