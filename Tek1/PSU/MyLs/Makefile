##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = my_ls
SRC  := my_ls.c others.c params.c my_printing.c
SRC  += my_printf.c
SRC  += $(addprefix my/my_, memmove.c realloc.c strlen.c strncmp.c putchar.c)
SRC  += $(addprefix my/my_, putstr_err.c putnchar.c putnbr_base.c)
SRC  += $(addprefix my/my_, min.c max.c putnbr_base_precision.c abs.c)
SRC  += $(addprefix my/my_, digit_count.c pow.c)
SRC  += $(addprefix parsing/, argument.c format.c variant.c context.c)
SRC  += $(addprefix parsing/parse_, string.c format.c positional_arg.c)
SRC  += $(addprefix parsing/parse_, character_flag.c width.c precision.c)
SRC  += $(addprefix parsing/parse_, length_modifier.c conversion.c)
SRC  += $(addprefix parsing/resolve_, arguments.c formats.c)
SRC  += $(addprefix printing/print_, di.c u.c f.c f_maj.c e.c e_maj.c g.c)
SRC  += $(addprefix printing/print_, g_maj.c b.c o.c x.c x_maj.c a.c a_maj.c)
SRC  += $(addprefix printing/print_, c.c lc.c s.c ls.c s_maj.c ls_maj.c n.c)
SRC  += $(addprefix printing/print_, p.c percentage.c error.c utils.c)
SRC  := $(addprefix src/, $(SRC))
OBJ = $(SRC:.c=.o)

CFLAGS = -std=c99 -g -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	@echo "Compiling $@..."
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $^ $(CFLAGS) -Iinclude -D_XOPEN_SOURCE=500

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
