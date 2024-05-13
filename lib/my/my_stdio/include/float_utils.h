/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for float specifiers
*/

#ifndef FLOAT_UTILS_
    #define FLOAT_UTILS_
    #define DOUBLE_PRECISION (2048 * 2)


typedef union inspector_u {
    double nb;
    long bytes;
} inspector_t;

char *handle_errors_float(double nb, int upper);

char *compute_double(double nb);

void round_float(char **float_str, char next_chr, char spec);


#endif /* FLOAT_UTILS_ */
