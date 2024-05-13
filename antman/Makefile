##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for antman
##

CC = gcc

LIB_DIR	=	../lib/my
SRC_DIR	=	./src
INCLUDE_DIR	=	../include

LIB_MATH	=	-lm
LIB_MY	=	-L..	-lmy

INCLUDE	=	-I$(INCLUDE_DIR)

CFLAGS += -Werror -Wextra -Wall $(INCLUDE) -g3

SRC	=	$(SRC_DIR)/main.c				\
		$(SRC_DIR)/lzw_encode.c			\
		$(SRC_DIR)/lzw_write_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

all:	$(NAME)

$(NAME):	lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)	$(LIB_MY) $(LIB_MATH)

lib:
	make -C ../lib/my

clean_lib:
	make -C ../lib/my fclean

clean:
	rm -f $(OBJ)
	../clean.sh

fclean:	clean clean_lib
	rm -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re clean_lib
