##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for antman
##

all:
	make -C ./antman
	make -C ./giantman

tests_run:
	make -C ./tests/unit_tests

clean:
	make -C ./tests/unit_tests clean
	make -C ./antman clean
	make -C ./giantman clean
	./clean.sh

fclean: clean
	make -C ./tests/unit_tests fclean
	make -C ./antman fclean
	make -C ./giantman fclean

re: fclean all

.PHONY: all clean fclean re
