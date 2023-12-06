##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAMEL = libmy.a

NAMEI = my.h

all: $(NAMEL)

$(NAMEL): $(OBJ)
	gcc -c $(OBJ)
	ar rc $(NAMEL) $(OBJ)
	cp $(NAMEL) ../$(NAMEL)
	cp $(NAMEI) ../../include/$(NAMEI)
	make clean

clean : $(shell rm -f $(OBJ))
