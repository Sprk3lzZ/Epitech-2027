##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = rush3
SRC = final_stumper.c
OBJ = $(SRC:.c=.o)
LIBMY = lib/my/libmy.a

LDFLAGS = -Llib/my/
LDLIBS = -lmy
CPPFLAGS = -Iinclude
CFLAGS = -std=c99 -w #-W -Wall -Wextra -Wpedantic

all: $(LIBMY) $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(OBJ): $(SRC)
	@echo "Compiling $@..."
	@$(CC) -c $(SRC) $(CFLAGS) $(CPPFLAGS)

$(LIBMY):
	$(MAKE) -C lib/my

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Fcleaning..."
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
