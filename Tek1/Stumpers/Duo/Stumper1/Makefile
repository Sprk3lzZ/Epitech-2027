##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := fractals
SRC := src/fractals.c src/getter.c src/my_lib.c src/my_getnbr.c src/my_compute_power_rec.c
OBJ := $(SRC:%.c=build/%.o)

CPPFLAGS := -Iinclude
CFLAGS := -W -Wall -Wextra -Wpedantic -g

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

love:
	@bear --append -- $(MAKE) -s

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -o $@ -c $< $(CPPFLAGS) $(CFLAGS)
