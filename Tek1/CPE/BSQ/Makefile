##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = bsq
SRC  = $(addprefix src/bsq/, bsq.c creation.c error.c getter.c main.c)
SRC += $(addprefix src/my/, my_get_nbr.c my_putchar.c my_putnbr.c my_strlen.c)
OBJ = $(SRC:src/%.c=objects/%.o)

CFLAGS = -std=c99 -g -W -Wall -Wextra -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o $@ $^

objects/%.o: src/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS) -I./include

clean:
	@echo "Cleaning..."
	@rm -rf objects/

fclean: clean
	@echo "Fcleaning..."
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
