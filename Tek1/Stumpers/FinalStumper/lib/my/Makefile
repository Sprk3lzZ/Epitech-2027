##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = libmy.a
SRC = my_strlen.c my_putchar.c my_putstr.c
SRC += my_strcmp.c my_put_nbr.c
OBJ = $(SRC:.c=.o)

CPPFLAGS = -I../../include
CFLAGS = -std=c99 -W -Wall -Wextra -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building $@..."
	@ar rcs $@ $(OBJ)

$(OBJ):
	@echo "Compiling $@..."
	@$(CC) -c $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)

fclean: clean
	@echo "FCleaning..."
	@rm -f $(NAME)

.PHONY: all clean fclean
