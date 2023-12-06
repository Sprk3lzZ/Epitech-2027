##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	= cat
CC	= gcc
RM	= rm -f
SRC	= cat.c main.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)

tests_run:
	$(CC) cat.c ../tests/test_cat.c -o tests --coverage -lgcov -lcriterion
	./tests

clean:
	$(RM) $(OBJS)
	$(RM) *.gcno
	$(RM) *.gcda

fclean: clean
	$(RM) $(NAME)
	$(RM) tests

re: fclean all
