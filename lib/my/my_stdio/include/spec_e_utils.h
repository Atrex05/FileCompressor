/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for exp modifiers utils
*/

#ifndef SPEC_E_UTILS_
    #define SPEC_E_UTILS_


void convert_to_exp(
    char *res, char *int_part,
    char *float_part, int *utils
);

void convert_0_to_exp(char *res, char *float_part, int is_upper);

void convert_int_to_exp(
    char *res, char *int_part,
    char *float_part, int is_up
);

void convert_dec_to_exp(
    char *res, char *int_part,
    char *float_part, int is_upper
);

void add_exponent(char *res, char sign, int pow_10, int is_upper);


#endif /* SPEC_E_UTILS_ */
