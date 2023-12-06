##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	= do-op

CC	= gcc

RM	= rm -f

SRC	= do_op.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L../lib/my/ -lmy

all: 	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re:     fclean all
