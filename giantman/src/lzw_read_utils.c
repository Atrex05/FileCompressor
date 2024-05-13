/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lzw utils
*/

#include "my_stdlib.h"
#include "my_str.h"

static const int CODES[] = {
    511, 1023, 2047, 4095,
    8191, 16383, 32767
};
static const int CODES_SIZE = sizeof(CODES) / sizeof(int);
static const unsigned int END_OF_FILE = 256;
static const int MAX_CODE_SIZE = 32767;

static int get_nb_of_bits(int code)
{
    int nb_bits = 9;

    for (int i = 0; i < CODES_SIZE; ++i) {
        if (code > CODES[i])
            nb_bits++;
        else
            break;
    }

    return nb_bits;
}

int read_n_bits(str_t *buff)
{
    static int available_bits = 0;
    static unsigned int pending_input = 0;
    static int current_code = 256;
    static size_t buff_idx = 0;
    int nb_bits = get_nb_of_bits(current_code);
    if (current_code < MAX_CODE_SIZE)
        current_code++;
    unsigned int data = 0;
    char c = 0;
    while (available_bits < nb_bits) {
        if (buff_idx >= buff->length)
            return END_OF_FILE;
        c = buff->data[buff_idx++];
        pending_input |= (c & 0xff) << available_bits;
        available_bits += 8;
    }
    data = pending_input & ~(~0U << nb_bits);
    pending_input >>= nb_bits;
    available_bits -= nb_bits;
    return data;
}
