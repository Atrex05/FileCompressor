/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** my_stdio declarations
*/

#ifndef INCLUDE_MY_STDIO_
    #define INCLUDE_MY_STDIO_
    #include <unistd.h>
    #include <stdarg.h>


int my_printf(const char *format, ...);
int my_sprintf(char *str, const char *format, ...);
int my_vasprintf(char **ret, const char *format, va_list *ap);
int my_dprintf(int fd, const char * format, ...);

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstderr(char const *str);
void my_puts(char const *str);


#endif /* INCLUDE_MY_STDIO_ */
