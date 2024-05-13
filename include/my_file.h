/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** my_file utils
*/

#ifndef INCLUDE_MY_FILE_
    #define INCLUDE_MY_FILE_
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include "my_list.h"
    #include "my_str.h"
    #define F_R         (O_RDONLY)
    #define F_W         (O_WRONLY)
    #define F_RW        (O_RDWR)
    #define F_A         (O_APPEND)
    #define F_C         (O_CREAT)
    #define F_T         (O_TRUNC)


typedef struct file_s {
    int fd;
    char *file_path;
    str_t *content;
    str_t *__cache;
    struct stat stats;
} file_t;

/**
 * @brief creates a new file instance
 *
 * @param file_path     the path of the file to open
 * @param file_mode     the mode in which the file will be open
 * @return a new file instance or NULL if there was an error
 */
file_t *file_create(char const *file_path, int const file_mode);

/**
 * @brief gets a new line in a file
 *
 * @param file  the file to get the line from
 * @return the new line in the file
 */
char *file_get_line(file_t *file);

/**
 * @brief loads the content of the file into file->content
 *
 * @param file  the file for wichi you want to load the content
 * @return the content of the file
 */
str_t *file_get_content(file_t *file);

/**
 * @brief writes a char * into a file
 *
 * @param file  the file to write to
 * @param str   the char* to write
 */
void file_write(file_t *file, char *str);

/**
 * @brief writes a formatted char* into a file (using printf syntax)
 *
 * @param file  the file to write to
 * @param fmt   the format string
 * @param ...   printf like arguments
 */
void file_fwrite(file_t *file, char *fmt, ...);

/**
 * @brief closes a file
 *
 * @param file  the file to close
 */
void file_close(file_t *file);

/**
 * @brief closes a file and frees its dependecies
 *
 * @param file  the file to close and free
 */
void file_free(file_t *file);


#endif /* INCLUDE_MY_FILE_ */
