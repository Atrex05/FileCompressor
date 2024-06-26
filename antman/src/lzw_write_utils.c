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

static void add_bits_to_buffer(
    str_t **buff, int size,
    int *pending_bits, unsigned int *pending_output
)
{
    while (*pending_bits >= size) {
        str_cadd(buff, *pending_output & 0xff);
        (*pending_output) >>= 8;
        (*pending_bits) -= 8;
    }
}

void write_n_bits(str_t **buff, unsigned int data)
{
    static unsigned int pending_output = 0;
    static int current_code = 256;
    static int pending_bits = 0;
    static int nb_bits = 9;

    nb_bits = get_nb_of_bits(current_code);
    if (current_code < MAX_CODE_SIZE)
        current_code++;
    pending_output |= data << pending_bits;
    pending_bits += nb_bits;

    add_bits_to_buffer(buff, 8, &pending_bits, &pending_output);
    if (data == END_OF_FILE)
        add_bits_to_buffer(buff, 0, &pending_bits, &pending_output);
}
