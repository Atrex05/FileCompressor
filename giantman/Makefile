##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for giantman
##

CC = gcc

LIB_DIR	=	../lib/my
SRC_DIR	=	./src
INCLUDE_DIR	=	../include

LIB_MATH	=	-lm
LIB_MY	=	-L..	-lmy

SRC	=	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/lzw_decode.c 	\
		$(SRC_DIR)/lzw_read_utils.c

INCLUDE	=	-I$(INCLUDE_DIR)

CFLAGS += -Werror -Wextra -Wall $(INCLUDE) -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

all:	$(NAME)

$(NAME):	lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)	$(LIB_MY) $(LIB_MATH)

lib:
	make -C ../lib/my

clean_lib:
	make -C	../lib/my fclean

clean:
	rm -f $(OBJ)
	../clean.sh

fclean:	clean clean_lib
	rm -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re clean_lib
