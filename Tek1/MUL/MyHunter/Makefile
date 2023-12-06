##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME := my_hunter
SRC := $(shell find src -type f -name "*.c")
OBJ := $(SRC:src/%.c=obj/%.o)

CFLAGS := -W -Wall -Wextra -Wpedantic -g
CPPFLAGS := -Iinclude
LDFLAGS :=
LDLIBS := -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)
