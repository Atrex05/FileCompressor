/*
** EPITECH PROJECT, 2022
** int specifier test
** File description:
** tests for specifier %b
*/

#include <criterion/criterion.h>
#include "my_str.h"
#include "my_file.h"
#include "antman/antman.h"

Test(lzw_encode, simple_string) {
    SMART_STR str_t *content = str_create("Hello World !");
    SMART_STR str_t *test = lzw_encode(content);
    char *res =
        "\x48\xca\xb0\x61\xf3\x06\xc4\x95\x37\x72\xd8\x90\x01\x11\x02\x20";

    for (size_t i = 0; i < test->length; ++i)
        cr_assert(test->data[i] == res[i]);
}

Test(lzw_encode, text_file) {
    SMART_FILE file_t *file = file_create("../test_files/test_files_students-1-ej.lyr", F_R);
    file_get_content(file);

    SMART_STR str_t *encoded = lzw_encode(file->content);
    SMART_STR str_t *decoded = lzw_decode(encoded);

    for (size_t i = 0; i < file->content->length; ++i)
        cr_assert(file->content->data[i] == decoded->data[i]);
}

Test(lzw_encode, html_file) {
    SMART_FILE file_t *file = file_create("../test_files/test_files_students-2-Amazon.html", F_R);
    file_get_content(file);

    SMART_STR str_t *encoded = lzw_encode(file->content);
    SMART_STR str_t *decoded = lzw_decode(encoded);

    for (size_t i = 0; i < file->content->length; ++i)
        cr_assert(file->content->data[i] == decoded->data[i]);
}

Test(lzw_encode, ppm_file) {
    SMART_FILE file_t *file = file_create("../test_files/test_files_students-3-Carapuce.ppm", F_R);
    file_get_content(file);

    SMART_STR str_t *encoded = lzw_encode(file->content);
    SMART_STR str_t *decoded = lzw_decode(encoded);

    for (size_t i = 0; i < file->content->length; ++i)
        cr_assert(file->content->data[i] == decoded->data[i]);
}
