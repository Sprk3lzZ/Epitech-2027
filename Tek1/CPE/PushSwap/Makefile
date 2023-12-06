##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME := push_swap
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:src/%.c=obj/%.o)

all: $(NAME)

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@gcc -o$(NAME) $(OBJ)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc -c -o$@ $< -Iinclude -W -Wall -Wextra -Wpedantic -g
