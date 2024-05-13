/*
** EPITECH PROJECT, 2022
** my_math
** File description:
** declarations
*/

#ifndef INCLUDE_MY_MATH_
    #define INCLUDE_MY_MATH_
    #include <math.h>
    #define MY_MAX(a, b)    ((a > b) ? (a) : (b))
    #define MY_MIN(a, b)    ((a < b) ? (a) : (b))
    #define MY_ABS(a)       ((a > 0) ? (a) : -(a))
    #define MY_FABS(a)      ((a > 0.0) ? (a) : -(a))
    #define MY_TO_DEG(r)    (r * (180.0 / (float)M_PI))
    #define MY_TO_RAD(r)    (r * ((float)M_PI / 180.0))


int my_pow(int number, int power);
int my_int_sqrt(int nb);
int my_is_prime(int nb);
int my_nbr_length(long int nb);
long long my_ll_pow(long long number, int power);


typedef struct vec2i_s {
    int x;
    int y;
} vec2i_t;

typedef struct vec2d_s {
    double x;
    double y;
} vec2d_t;

typedef struct vec3i_s {
    int x;
    int y;
    int z;
} vec3i_t;

typedef struct vec3f_s {
    float x;
    float y;
    float z;
} vec3f_t;

typedef struct vec3d_s {
    double x;
    double y;
    double z;
} vec3d_t;


#endif /* INCLUDE_MY_MATH_ */
