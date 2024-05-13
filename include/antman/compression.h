/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lz77
*/

#ifndef INCLUDE_ANTMAN_LZ77_
    #define INCLUDE_ANTMAN_LZ77_
    #include "my_str.h"


//
// 255    < code <=   511   : 9 bits
// 511    < code <=  1023   : 10 bits
// 1023   < code <=  2047   : 11 bits
// 2047   < code <=  4095   : 12 bits
// 4095   < code <=  8191   : 13 bits
// 8191   < code <= 16383   : 14 bits
// 16383  < code <= 32767   : 15 bits
//

str_t *lzw_encode(str_t *file_content);
str_t *lzw_decode(str_t *file_compressed);

int read_n_bits(str_t *buff);
void write_n_bits(str_t **buff, unsigned int data);


#endif /* INCLUDE_ANTMAN_LZ77_ */
