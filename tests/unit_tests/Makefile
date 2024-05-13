##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for compiling my lib
##

CC = gcc

ANTMAN_SRC	=	../../antman/src
GIANTMAN_SRC	=	../../giantman/src

SRC	=	$(ANTMAN_SRC)/lzw_encode.c			\
		$(ANTMAN_SRC)/lzw_write_utils.c		\
		$(GIANTMAN_SRC)/lzw_decode.c		\
		$(GIANTMAN_SRC)/lzw_read_utils.c

TESTS	=	./test_lzw_encode.c

INCLUDE	=	-I../../include

LIB	=	-L../../ -lmy

CFLAGS += -Werror -Wextra -Wall -pedantic $(INCLUDE)

TEST_NAME	=	unit_tests

all: tests_run

unit_tests:
	make -C ../../lib/my
	$(CC) -o $(TEST_NAME) $(SRC) $(TESTS) $(LIB) $(INCLUDE) \
	--coverage -lcriterion

tests_run:
	make unit_tests && ./$(TEST_NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(TEST_NAME)

.PHONY: tests_run unit_tests clean fclean
