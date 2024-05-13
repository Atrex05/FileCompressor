/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** my_str declarations
*/

#ifndef INCLUDE_MY_STR_
    #define INCLUDE_MY_STR_
    #include <stddef.h>
    #include "my_vec.h"


char my_upcase(char chr);
char my_lowcase(char chr);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);

size_t my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, size_t n);
char *my_strdup(char const *src);
void my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);

int my_isalpha(char chr);
int my_islower(char chr);
int my_isnum(char chr);
int my_isprintable(char chr);
int my_isupper(char chr);
int my_isalphanum(char chr);

int my_str_isalpha(char const *str);
int my_str_isfloat(char const *str);
int my_str_isint(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);


typedef struct str_s {
    size_t length;
    size_t capacity;
    char data[0];
} str_t;

typedef struct vec_str_s {
    vec_base_t base;
    str_t *data[0];
} vec_str_t;

/**
 * @brief creates a string
 *
 * @param init      char* to init the string
 * @return a string
 */
str_t *str_create(char const *init);

/**
 * @brief creates a string with given number of characters
 *
 * @param init      char* to init the string
 * @param n         number of characters in init
 * @return a string
 */
str_t *str_ncreate(char const *init, size_t n);

/**
 * @brief splits a string into a vector of strings
 *
 * @param str       string to split
 * @param delims    string of delimiters
 * @return split string as a vector
 */
vec_str_t *str_split(str_t *str, str_t *delims);

/**
 * @brief checks if str starts with start
 *
 * @param str       string to perform the check on
 * @param start     start string
 * @return 1 or 0 if the string ends or doesn't I do to
 */
int str_startswith(str_t *str, str_t *start);

/**
 * @brief checks if str ends with end
 *
 * @param str   string to prerform the check on
 * @param end   end string
 * @return 1 or 0 if the string ends or doesn't I do to
 */
int str_endsswith(str_t *str, str_t *end);

/**
 * @brief slices a string
 *
 * @param str       string to slice
 * @param start     start of slice
 * @param end       end of slice
 * @return the sliced string
 */
str_t **str_slice(str_t **str, size_t start, size_t end);

/**
 * @brief compares 2 strings
 *
 * @param s1    first string to compare
 * @param s2    second string to compare
 * @return <0, 0 or >0 if s1 is respectively smaller, equal or greater than s2
 */
int str_compare(str_t *s1, str_t *s2);

/**
 * @brief compares the n first characters of 2 strings
 *
 * @param s1    first string to compare
 * @param s2    second string to compare
 * @return <0, 0 or >0 if s1 is respectively smaller, equal or greater than s2
 */
int str_ncompare(str_t *s1, str_t *s2, size_t n);

/**
 * @brief checks if a string contains a character
 *
 * @param str   string to check
 * @param c     character to check
 * @return 1 or 0 if the character is in the string or isn't
 */
int str_contains(str_t *str, char c);

/**
 * @brief duplicates a string (with malloc)
 *
 * @param old   string to duplicate
 * @return the duplicate of the old string
 */
str_t *str_dup(str_t *old);

/**
 * @brief resizes a string
 *
 * @param str       string to resize
 * @return the string resized to a longer length
 */
str_t **str_resize(str_t **str, size_t new_len);

/**
 * @brief adds a char* to a string
 *
 * @param str   destination string
 * @param new   char* to add
 * @return the string with the char* added to its content
 */
str_t **str_add(str_t **str, char const *new);

/**
 * @brief adds n characters of a char* to a string
 *
 * @param str   destination string
 * @param new   char* to add
 * @param n     number of characters to add
 * @return the string with n characters added to its content
 */
str_t **str_nadd(str_t **str, char const *new, size_t n);

/**
 * @brief adds formatted char* to a string (using printf syntax)
 *
 * @param str   destination string
 * @param fmt   format string
 * @param ...   arguments following the printf syntax
 * @return the string with the formatted output added to its content
 */
str_t **str_fadd(str_t **str, char const *fmt, ...);

/**
 * @brief clears a string
 *
 * @param str   string to clear
 * @return the string cleared
 */
str_t **str_clear(str_t **str);

/**
 * @brief trims the left side of a string
 *
 * @param str   string to trim
 * @param pad   character to remove while trimming
 * @return the string with its content trimmed on the left
 */
str_t **str_ltrim(str_t **str, char pad);

/**
 * @brief trims the right side of a string
 *
 * @param str   string to trim
 * @param pad   character to remove while trimming
 * @return the string with its content trimmed on the right
 */
str_t **str_rtrim(str_t **str, char pad);

/**
 * @brief trims both sides of a string
 *
 * @param str   string to trim
 * @param pad   character to remove while trimming
 * @return the string with its content trimmed on both sides
 */
str_t **str_trim(str_t **str, char pad);

/**
 * @brief prints a string to the stdout
 *
 * @param str   string to print
 */
void str_print(str_t *str);

/**
 * @brief adds mutliple char* to a string
 *
 * @param str   destination string
 * @param argc  number of char* to add
 * @param ...   char* to add
 * @return string with all the char* added to its content
 */
str_t **str_vadd(str_t **str, int argc, ...);

/**
 * @brief adds a character to a string
 *
 * @param str   destination string
 * @param new   character to add
 * @return string with the character added to its content
 */
str_t **str_cadd(str_t **str, char const new);

/**
 * @brief concatenates a string to another one
 *
 * @param str   destination string
 * @param new   string to add
 * @return the concatenation of the 2 strings stored in str
 */
str_t **str_stradd(str_t **str, str_t const *new);

/**
 * @brief checks if 2 strings are equal
 *
 * @param s1    string 1
 * @param s2    string 2
 * @return 1 if string 1 and string 2 are equal or 0
 */
int str_eq(str_t *s1, str_t *s2);


#endif /* INCLUDE_MY_STR_ */
