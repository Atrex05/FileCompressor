##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_ls
##

CC = gcc

INCLUDE_DIR	=	../../include

YAML_DIR	=	./my_yaml
MAP_DIR		=	./my_map
VEC_DIR		=	./my_vec
MATH_DIR	=	./my_math
STDLIB_DIR	=	./my_stdlib
STR_DIR		=	./my_str
FILE_DIR	=	./my_file
STDIO_DIR	=	./my_stdio
LIST_DIR	=	./my_list
MATRIX_DIR	=	./my_matrix
ARRAY_DIR	=	./my_array

INCLUDE_FILE_DIR	=	$(FILE_DIR)/include
INCLUDE_STDIO_DIR	=	$(STDIO_DIR)/include
INCLUDE_LIST_DIR	=	$(LIST_DIR)/include
INCLUDE_MATRIX_DIR	=	$(MATRIX_DIR)/include


MY_YAML		=	$(YAML_DIR)/my_yaml.c


MY_VEC		=	$(VEC_DIR)/my_vec.c			\
				$(VEC_DIR)/setters.c		\
				$(VEC_DIR)/misc.c			\
				$(VEC_DIR)/iterators.c		\
				$(VEC_DIR)/sort.c


MY_MAP		=	$(MAP_DIR)/my_map.c				\
				$(MAP_DIR)/getters.c			\
				$(MAP_DIR)/setters.c			\
				$(MAP_DIR)/utils.c


MY_MATH		=	$(MATH_DIR)/my_int_sqrt.c			\
				$(MATH_DIR)/my_pow.c	 			\
				$(MATH_DIR)/my_ll_pow.c	 			\
				$(MATH_DIR)/my_is_prime.c


MY_STDLIB	=	$(STDLIB_DIR)/my_atoi.c		\
				$(STDLIB_DIR)/my_itoa.c		\
				$(STDLIB_DIR)/my_atof.c		\
				$(STDLIB_DIR)/my_calloc.c	\
				$(STDLIB_DIR)/my_memcpy.c	\
				$(STDLIB_DIR)/my_memset.c	\
				$(STDLIB_DIR)/auto_free.c	\
				$(STDLIB_DIR)/vfree.c


MY_MATRIX	=	$(MATRIX_DIR)/my_matrix.c 	\
				$(MATRIX_DIR)/advanced_op.c	\
				$(MATRIX_DIR)/simple_op.c	\
				$(MATRIX_DIR)/inverse.c		\
				$(MATRIX_DIR)/determinant.c


MY_ARRAY 	=	$(ARRAY_DIR)/array.c


MY_LIST		=	$(LIST_DIR)/my_list.c		\
				$(LIST_DIR)/setters.c		\
				$(LIST_DIR)/iterators.c


MY_STR		=	$(STR_DIR)/str_type/my_str.c	\
				$(STR_DIR)/str_type/adders.c	\
				$(STR_DIR)/str_type/compare.c	\
				$(STR_DIR)/str_type/checks.c	\
				$(STR_DIR)/str_type/trim.c		\
				$(STR_DIR)/str_type/format.c	\
				$(STR_DIR)/str_type/misc.c		\
				$(STR_DIR)/str_type/getters.c	\
				$(STR_DIR)/my_isalpha.c		 	\
				$(STR_DIR)/my_isalphanum.c		\
				$(STR_DIR)/my_islower.c			\
				$(STR_DIR)/my_isnum.c			\
				$(STR_DIR)/my_isprintable.c		\
				$(STR_DIR)/my_isupper.c			\
				$(STR_DIR)/my_lowcase.c			\
				$(STR_DIR)/my_nbr_length.c		\
				$(STR_DIR)/my_revstr.c			\
				$(STR_DIR)/my_str_isalpha.c		\
				$(STR_DIR)/my_str_islower.c		\
				$(STR_DIR)/my_str_isfloat.c		\
				$(STR_DIR)/my_str_isint.c		\
				$(STR_DIR)/my_str_isnum.c		\
				$(STR_DIR)/my_str_isprintable.c	\
				$(STR_DIR)/my_str_isupper.c		\
				$(STR_DIR)/my_strcat.c			\
				$(STR_DIR)/my_strcmp.c			\
				$(STR_DIR)/my_strcpy.c			\
				$(STR_DIR)/my_strdup.c			\
				$(STR_DIR)/my_strlen.c			\
				$(STR_DIR)/my_strlowcase.c		\
				$(STR_DIR)/my_strncat.c			\
				$(STR_DIR)/my_strncmp.c			\
				$(STR_DIR)/my_strncpy.c			\
				$(STR_DIR)/my_strupcase.c		\
				$(STR_DIR)/my_upcase.c


MY_FILE		=	$(FILE_DIR)/my_file.c 			\
				$(FILE_DIR)/getters.c 			\
				$(FILE_DIR)/setters.c			\
				$(FILE_DIR)/get_line_utils.c


MY_STDIO	=	$(STDIO_DIR)/my_printf.c								\
				$(STDIO_DIR)/my_sprintf.c								\
				$(STDIO_DIR)/my_dprintf.c								\
				$(STDIO_DIR)/my_vasprintf.c								\
				$(STDIO_DIR)/my_putchar.c								\
				$(STDIO_DIR)/my_puts.c									\
				$(STDIO_DIR)/my_putstderr.c								\
				$(STDIO_DIR)/my_putstr.c								\
				$(STDIO_DIR)/src/core.c    								\
				$(STDIO_DIR)/src/parser.c								\
				$(STDIO_DIR)/src/buffer.c								\
				$(STDIO_DIR)/src/exec_specifier.c						\
				$(STDIO_DIR)/src/post_processor.c						\
				$(STDIO_DIR)/src/state.c								\
				$(STDIO_DIR)/src/utils/buffer_utils.c					\
				$(STDIO_DIR)/src/utils/exec_specifiers_utils.c			\
				$(STDIO_DIR)/src/utils/post_processor_utils.c			\
				$(STDIO_DIR)/src/utils/post_processor_extractors.c		\
				$(STDIO_DIR)/src/specifiers/compute_spec_a.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_c.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_e.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_g.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_o.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_u.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_b.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_d.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_f.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_n.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_p.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_t.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_s.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_x.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_percent.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_int_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/str_operations.c		\
				$(STDIO_DIR)/src/specifiers/utils/float_utils.c			\
				$(STDIO_DIR)/src/specifiers/utils/round_float.c			\
				$(STDIO_DIR)/src/specifiers/utils/spec_e_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_a_utils.c


INCLUDE	=	-I$(INCLUDE_STDIO_DIR) -I$(INCLUDE_LIST_DIR) -I$(INCLUDE_DIR) \
			-I$(INCLUDE_FILE_DIR) -I$(INCLUDE_MATRIX_DIR)


CFLAGS += -Werror -Wextra -Wall $(INCLUDE) -g3

OBJ	=	$(MY_STDIO:.c=.o) $(MY_LIST:.c=.o) $(MY_STR:.c=.o) \
		$(MY_FILE:.c=.o) $(MY_MATRIX:.c=.o) $(MY_ARRAY:.c=.o) \
		$(MY_STDLIB:.c=.o) $(MY_MATH:.c=.o) $(MY_VEC:.c=.o) \
		$(MY_MAP:.c=.o) $(MY_YAML:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../

clean:
	rm -f $(OBJ)
	../../clean.sh

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
