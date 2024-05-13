/*
** EPITECH PROJECT, 2022
** my_file.c
** File description:
** my_file utils
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my_stdlib.h"
#include "my_str.h"

#include "my_file.h"

static int const BUFF_SIZE = 4096;

static int file_is_valid(char const *file_path)
{
    struct stat file_stat;
    int st = stat(file_path, &file_stat);
    int fd = open(file_path, O_RDONLY);

    if (fd == -1) return 1;
    if (st != 0) return 1;
    if (!S_ISREG(file_stat.st_mode)) {
        return 1;
    }

    close(fd);
    return 0;
}

file_t *file_create(char const *file_path, int const file_mode)
{
    if (file_is_valid(file_path) != 0)
        return NULL;

    file_t *file = malloc(sizeof(file_t));

    if (file == NULL)
        return NULL;

    stat(file_path, &file->stats);
    file->file_path = my_strdup(file_path);
    file->content = str_create("");
    file->__cache = str_create("");
    if (!file->__cache || !file->file_path || !file->content)
        return NULL;
    str_resize(&file->__cache, BUFF_SIZE);
    file->fd = open(file_path, file_mode);

    return file;
}

void file_close(file_t *file)
{
    close(file->fd);
    file->fd = -1;
}

void file_free(file_t *file)
{
    if (file->fd != -1) {
        file_close(file);
    }
    free(file->content);
    free(file->__cache);
    free(file->file_path);
    free(file);
}
