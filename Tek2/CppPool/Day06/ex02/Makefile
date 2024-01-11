##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

POOL = -std=c++20 -Wall -Wextra -Werror

SRC = StupidUnitConverter.cpp \

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME = StupidUnitConverter

all: $(NAME)

$(NAME): $(OBJ)
	@g++ -o $(NAME) $(SRC) $(POOL)
	@rm -f *.o source/*.o library/*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all re clean fclean
