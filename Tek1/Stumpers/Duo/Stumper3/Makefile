##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := cesar
SRC := src/cesar.c src/utils.c src/extract.c
OBJ := $(SRC:%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -W -Wall -Wextra -Wpedantic -g

all: $(NAME)

clean:
	@rm -rf build
	@rm -rf crypt

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)
